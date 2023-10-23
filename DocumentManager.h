#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include <unordered_map>
#include <unordered_set>
#include <string>

class DocumentManager {
    public:
    void addDocument(std::string name, int id, int license_limit);
    void addPatron(int patronID);
    int search(std::string name);
    bool borrowDocument(int docid, int patronID);
    void returnDocument(int docid, int patronID);
    private:
        struct Document {
            std::string name;
            int licenseLimit;
            std::unordered_set<int> patronIDs;
        };
        std::unordered_map<int, Document> documents;
        std::unordered_set<int> patrons;
        std::unordered_map<std::string, int> document_name_id;//docNameToID--document_name_id

};

#endif 
