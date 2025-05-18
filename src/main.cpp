#include "PdfMerger.h"
#include "PdfSplitter.h"
#include "IPdfSplitter.h"

using namespace PoDoFo;

int main() {
    try {
        // Initialize the merger and splitter
        PdfMerger merger;
        PdfSplitter splitter;

        // Merge multiple PDFs
        std::cout << "\n🔄 Merging PDFs...\n";
        merger.Merge("merged_output.pdf", "../hello.pdf", "../hello2.pdf");

        // Split the merged PDF
        std::cout << "\n✂️ Splitting the merged PDF...\n";
        splitter.Split("merged_output.pdf", "split_page_%d.pdf");

        std::cout << "\n✅ Operations completed successfully.\n";
    } catch (const PdfError& e) {
        std::cerr << "\n❌ PoDoFo error: " << e.what() << "\n";
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "\n❌ Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
