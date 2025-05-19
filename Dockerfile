# syntax=docker/dockerfile:1.6

# Stage 1: Build environment
FROM --platform=$BUILDPLATFORM ubuntu:22.04 as builder

# Configure environment
ENV DEBIAN_FRONTEND=noninteractive \
    CMAKE_BUILD_TYPE=Release \
    VCPKG_ROOT=/opt/vcpkg

# Install base dependencies
RUN <<EOF
apt-get update
apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    ninja-build \
    git \
    wget \
    tar \
    curl \
    ca-certificates
rm -rf /var/lib/apt/lists/*
EOF

# Install vcpkg
RUN git clone https://github.com/microsoft/vcpkg $VCPKG_ROOT && \
    $VCPKG_ROOT/bootstrap-vcpkg.sh -disableMetrics && \
    $VCPKG_ROOT/vcpkg integrate install

# Install dependencies
RUN $VCPKG_ROOT/vcpkg install \
    podofo \
    gtest

WORKDIR /app
COPY . .

# Build with CMake
RUN <<EOF
cmake -B build -G Ninja \
    -DCMAKE_TOOLCHAIN_FILE=${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake \
    -DBUILD_TESTING=ON
cmake --build build --parallel $(nproc)
EOF

# Stage 2: Test runner
FROM builder as tester
RUN cd build && \
    ctest --output-on-failure --output-junit test-results.xml

# Stage 3: Production image
FROM ubuntu:22.04 as production

# Install runtime dependencies
RUN <<EOF
apt-get update && \
apt-get install -y --no-install-recommends \
    libpodofo0 \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*
EOF

WORKDIR /app
COPY --from=builder /app/build/Folium .

# Security hardening
RUN addgroup --system appuser && \
    adduser --system --ingroup appuser appuser && \
    chown appuser:appuser /app/Folium

USER appuser
ENTRYPOINT ["./Folium"]