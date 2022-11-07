#ifndef SECURITY_CONTEXT_H
#define SECURITY_CONTEXT_H
#include <memory>




class SecurityContext {
public:
    bool allowLegacyUnsafeRenegotiation;


    external  SecurityContext(bool withTrustedRoots);

    external static SecurityContext defaultContext();

    void usePrivateKey(String file, String password);

    void usePrivateKeyBytes(List<int> keyBytes, String password);

    void setTrustedCertificates(String file, String password);

    void setTrustedCertificatesBytes(List<int> certBytes, String password);

    void useCertificateChain(String file, String password);

    void useCertificateChainBytes(List<int> chainBytes, String password);

    void setClientAuthorities(String file, String password);

    void setClientAuthoritiesBytes(List<int> authCertBytes, String password);

    external static bool alpnSupported();

    void setAlpnProtocols(bool isServer, List<String> protocols);

private:

    static Uint8List _protocolsToLengthEncoding(List<String> protocols);

    static Uint8List _protocolsToLengthEncodingNonAsciiBailout(List<String> protocols);

};

#endif