#include "PdfSplitter.h"

#include <iostream>
#include <cstdio>     
#include <stdexcept>  
#include <podofo/podofo.h>

void PdfSplitter::Split(const std::string& inputFile, const std::string& outputPattern) {
    try {
        PoDoFo::PdfMemDocument inputDoc;
        inputDoc.Load(inputFile.c_str());
        int pageCount = inputDoc.GetPages().GetCount();

        for (int i = 0; i < pageCount; ++i) {
            PoDoFo::PdfMemDocument singlePageDoc;
            singlePageDoc.GetPages().AppendDocumentPages(inputDoc, i, 1);

            // Generate the output filename safely
            char buffer[256];
            if (std::snprintf(buffer, sizeof(buffer), outputPattern.c_str(), i + 1) < 0) {
                throw std::runtime_error("Error formatting output filename");
            }

            singlePageDoc.Save(buffer);
            std::cout << "✅ Saved page " << (i + 1) << " as " << buffer << std::endl;
        }
    } catch (const PoDoFo::PdfError& e) {
        std::cerr << "❌ PoDoFo error: " << e.what() << std::endl;
        throw;
    } catch (const std::exception& e) {
        std::cerr << "❌ Error: " << e.what() << std::endl;
        throw;
    }
}
