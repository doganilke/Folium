#include "PdfMerger.h"

void PdfMerger::Merge(const std::string& outputFile, const std::vector<std::string>& inputFiles) {
    MergeImpl(outputFile, inputFiles);
}

void PdfMerger::MergeImpl(const std::string& outputFile, const std::vector<std::string>& inputFiles) {
    PoDoFo::PdfMemDocument outputDoc;
    try {
        for (const auto& file : inputFiles) {
            AppendDocumentPages(outputDoc, file);
        }
        outputDoc.Save(outputFile.c_str());
        std::cout << "✅ Merged PDF saved as " << outputFile << std::endl;
    } catch (const PoDoFo::PdfError& e) {
        std::cerr << "❌ PoDoFo error: " << e.what() << std::endl;
        throw;
    }
}

void PdfMerger::AppendDocumentPages(PoDoFo::PdfMemDocument& outputDoc, const std::string& filename) {
    PoDoFo::PdfMemDocument doc;
    doc.Load(filename.c_str());
    int pages = doc.GetPages().GetCount();
    for (int i = 0; i < pages; ++i) {
        outputDoc.GetPages().AppendDocumentPages(doc, i, 1);
    }
}
