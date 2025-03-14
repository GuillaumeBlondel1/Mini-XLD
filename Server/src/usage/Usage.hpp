#ifndef __USAGE__
    #define __USAGE__

#include <string>

namespace Usage
{
    const std::string help = "Usage: \n"
        "    ./XLD-Server -h | ./XLD-Server <FileConfig>.json\n"
        "\n"
        "    - [-h]: Display usage.\n"
        "    - [<FileConfig>.json]: File config for start server.\n";

    void usage(int argc, const char **argv);
}

#endif
