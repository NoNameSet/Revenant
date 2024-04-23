#ifndef REVENANT_STRPACKFILEMANAGER_H
#define REVENANT_STRPACKFILEMANAGER_H

class strPackfileManager
{
public:
    static int RegisterIndividualFile(int* result, const char* file, bool quitOnBadVersion, const char* relativePath, bool quitIfMissing, bool overlayIfExists);

    static void InitialisePatterns();
};

#endif //REVENANT_STRPACKFILEMANAGER_H