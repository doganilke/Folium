# Use an official Ubuntu base image
FROM ubuntu:22.04 AS production

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive

# Install build tools and dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    pkg-config \
    ninja-build \
    libfreetype6-dev \
    libfontconfig1-dev \
    libssl-dev \
    libxml2-dev \
    zlib1g-dev \
    libjpeg-dev \
    libtiff-dev \
    libpng-dev \
    git \
    wget \
    curl \
    && rm -rf /var/lib/apt/lists/*

# Clone and build PoDoFo
RUN git clone --branch master https://github.com/podofo/podofo.git /podofo && \
    cd /podofo && \
    cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release && \
    cmake --build build && \
    cmake --install build

# Clone and build Google Test
RUN git clone --branch release-1.11.0 https://github.com/google/googletest.git /googletest && \
    cd /googletest && \
    cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release && \
    cmake --build build && \
    cmake --install build

# Set working directory for your app
WORKDIR /app

# Copy your application source code
COPY . .

# Build your app
RUN cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release && \
    cmake --build build

# Default command to run your app
CMD ["./build/Folium"]
