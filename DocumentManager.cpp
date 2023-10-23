#include "DocumentManager.h"

void DocumentManager::addDocument(std::string name, int id, int license_limit) {
    if (documents.find(id) != documents.end()) 
    {
      
    }

    if (document_name_id.find(name) != document_name_id.end()) 
    {
       
    }

    Document document_get;
    document_get.name = name;
    document_get.licenseLimit = license_limit;
    documents[id] = document_get;
    document_name_id[name] = id;
}

void DocumentManager::addPatron(int patronID) {
    patrons.insert(patronID);
}

int DocumentManager::search(std::string name) {
    if (document_name_id.find(name) != document_name_id.end()) {
        return document_name_id[name];
    }
    return 0;  
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
    if (documents.find(docid) != documents.end() && patrons.find(patronID) != patrons.end()) {
        Document& doc = documents[docid];
        if (doc.patronIDs.size() < doc.licenseLimit) {
            doc.patronIDs.insert(patronID);
            return true;  
        }
    }
    return false;  
}

void DocumentManager::returnDocument(int docid, int patronID) {
    if (documents.find(docid) != documents.end()) {
        Document& doc = documents[docid];
        doc.patronIDs.erase(patronID);
    }
}
