//
// Created by Alexander Cochrane on 2017-04-06.
//

#include "filehandler.h"

//filehandler open code
bst filehandler::loadIntoAVLTree(std::string fileName) {
    bst searchtree;
    std::ifstream ifs(fileName);
    if (!ifs) {
        throw std::invalid_argument("Bad file");
    }
    std::string temp;
    while (!ifs.eof()) {
        getline(ifs, temp);
        searchtree.Insert(temp);
    }
    ifs.close();
    return searchtree;
}

std::string filehandler::loadIntoString(std::string fileName) {
    std::string out = "";

    std::ifstream ifs(fileName);
    if (!ifs) {
        throw std::invalid_argument("Bad file");
    }
    std::string temp;
    while (!ifs.eof()) {
        safeGetLine(ifs,temp);
        out += temp;
    }
    ifs.close();
    return out;
}

// found this on stackoverflow. thanks to user763305 & Jimbo,
// and Aaron McDaid for asking the question so I didn't have to.
// http://stackoverflow.com/questions/6089231/getting-std-ifstream-to-handle-lf-cr-and-crlf
// also good on these guys for giving an answer that isn't "use boost"
std::istream& filehandler::safeGetLine(std::istream& is, std::string& t)
{
    t.clear();

    // The characters in the stream are read one-by-one using a std::streambuf.
    // That is faster than reading them one-by-one using the std::istream.
    // Code that uses streambuf this way must be guarded by a sentry object.
    // The sentry object performs various tasks,
    // such as thread synchronization and updating the stream state.

    std::istream::sentry se(is, true);
    std::streambuf* sb = is.rdbuf();

    for(;;) {
        int c = sb->sbumpc();
        switch (c) {
            case '\n':
                return is;
            case '\r':
                if(sb->sgetc() == '\n')
                    sb->sbumpc();
                return is;
            case EOF:
                // Also handle the case when the last line has no line ending
                if(t.empty())
                    is.setstate(std::ios::eofbit);
                return is;
            default:
                t += (char)c;
        }
    }
}