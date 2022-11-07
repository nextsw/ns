#ifndef ISOLATE_NAME_SERVER_H
#define ISOLATE_NAME_SERVER_H
#include <memory>




class IsolateNameServer {
public:

    static SendPort lookupPortByName(String name);

    static bool registerPortWithName(String name, SendPort port);

    static bool removePortNameMapping(String name);

private:

    void  _();

    static SendPort _lookupPortByName(String name);

    static bool _registerPortWithName(String name, SendPort port);

    static bool _removePortNameMapping(String name);

};

#endif