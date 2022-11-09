#ifndef DART_IO_NAMESPACE_IMPL
#define DART_IO_NAMESPACE_IMPL
#include <base.hpp>

#include <dart/core/core.hpp>


class _NamespaceCls : public ObjectCls {
public:

private:

    extern static _Namespace _namespace();
    extern static int _namespacePointer();
    extern static void _setupNamespace(auto namespace);
};
using _Namespace = std::shared_ptr<_NamespaceCls>;


#endif