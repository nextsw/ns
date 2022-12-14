#ifndef DART_IO_SECURITY_CONTEXT
#define DART_IO_SECURITY_CONTEXT
#include <base.hpp>

#include <dart/core/core.hpp>


class SecurityContextCls : public ObjectCls {
public:
    bool allowLegacyUnsafeRenegotiation;


     SecurityContextCls(bool withTrustedRoots);
    static SecurityContext defaultContext();
    virtual void usePrivateKey(String file, String password);
    virtual void usePrivateKeyBytes(List<int> keyBytes, String password);
    virtual void setTrustedCertificates(String file, String password);
    virtual void setTrustedCertificatesBytes(List<int> certBytes, String password);
    virtual void useCertificateChain(String file, String password);
    virtual void useCertificateChainBytes(List<int> chainBytes, String password);
    virtual void setClientAuthorities(String file, String password);
    virtual void setClientAuthoritiesBytes(List<int> authCertBytes, String password);
    static bool alpnSupported();
    virtual void setAlpnProtocols(List<String> protocols, bool isServer);
private:

    static Uint8List _protocolsToLengthEncoding(List<String> protocols);

    static Uint8List _protocolsToLengthEncodingNonAsciiBailout(List<String> protocols);

};
using SecurityContext = std::shared_ptr<SecurityContextCls>;


#endif