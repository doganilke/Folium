#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <podofo/podofo.h>
#include "IPdfMerger.h"

class PdfMerger : public IPdfMerger {
public:
    void Merge(const std::string& outputFile, const std::vector<std::string>& inputFiles) override;

    template<typename... Files>
    void Merge(const std::string& outputFile, Files&&... files) {
        MergeImpl(outputFile, { std::forward<Files>(files)... });
    }

private:
    void MergeImpl(const std::string& outputFile, const std::vector<std::string>& inputFiles);
    void AppendDocumentPages(PoDoFo::PdfMemDocument& outputDoc, const std::string& filename);
};
