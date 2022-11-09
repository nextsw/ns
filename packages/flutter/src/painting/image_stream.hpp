#ifndef PACKAGES_FLUTTER_SRC_PAINTING_IMAGE_STREAM
#define PACKAGES_FLUTTER_SRC_PAINTING_IMAGE_STREAM
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>


class ImageInfoCls : public ObjectCls {
public:
    Image image;

    double scale;

    String debugLabel;


     ImageInfoCls(String debugLabel, Image image, double scale);

    virtual ImageInfo clone();

    virtual bool isCloneOf(ImageInfo other);

    virtual int sizeBytes();

    virtual void dispose();

    virtual String toString();

    virtual int hashCode();

    virtual bool operator==(Object other);

private:

};
using ImageInfo = std::shared_ptr<ImageInfoCls>;

class ImageStreamListenerCls : public ObjectCls {
public:
    ImageListener onImage;

    ImageChunkListener onChunk;

    ImageErrorListener onError;


     ImageStreamListenerCls(ImageChunkListener onChunk, ImageErrorListener onError, ImageListener onImage);

    virtual int hashCode();

    virtual bool operator==(Object other);

private:

};
using ImageStreamListener = std::shared_ptr<ImageStreamListenerCls>;

class ImageChunkEventCls : public ObjectCls {
public:
    int cumulativeBytesLoaded;

    int expectedTotalBytes;


     ImageChunkEventCls(int cumulativeBytesLoaded, int expectedTotalBytes);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using ImageChunkEvent = std::shared_ptr<ImageChunkEventCls>;

class ImageStreamCls : public ObjectCls {
public:

     ImageStreamCls();
    virtual ImageStreamCompleter completer();

    virtual void setCompleter(ImageStreamCompleter value);

    virtual void addListener(ImageStreamListener listener);

    virtual void removeListener(ImageStreamListener listener);

    virtual Object key();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    ImageStreamCompleter _completer;

    List<ImageStreamListener> _listeners;


};
using ImageStream = std::shared_ptr<ImageStreamCls>;

class ImageStreamCompleterHandleCls : public ObjectCls {
public:

    virtual void dispose();

private:
    ImageStreamCompleter _completer;


    virtual void  _(ImageStreamCompleter _completer);

};
using ImageStreamCompleterHandle = std::shared_ptr<ImageStreamCompleterHandleCls>;

class ImageStreamCompleterCls : public ObjectCls {
public:
    String debugLabel;


    virtual bool hasListeners();

    virtual void addListener(ImageStreamListener listener);

    virtual ImageStreamCompleterHandle keepAlive();

    virtual void removeListener(ImageStreamListener listener);

    virtual void addOnLastListenerRemovedCallback(VoidCallback callback);

    virtual void removeOnLastListenerRemovedCallback(VoidCallback callback);

    virtual void setImage(ImageInfo image);

    virtual void reportError(DiagnosticsNode context, Object exception, InformationCollector informationCollector, bool silent, StackTrace stack);

    virtual void reportImageChunkEvent(ImageChunkEvent event);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder description);

private:
    List<ImageStreamListener> _listeners;

    ImageInfo _currentImage;

    FlutterErrorDetails _currentError;

    bool _hadAtLeastOneListener;

    bool _addingInitialListeners;

    int _keepAliveHandles;

    bool _disposed;

    List<VoidCallback> _onLastListenerRemovedCallbacks;


    virtual void _maybeDispose();

    virtual void _checkDisposed();

};
using ImageStreamCompleter = std::shared_ptr<ImageStreamCompleterCls>;

class OneFrameImageStreamCompleterCls : public ImageStreamCompleterCls {
public:

     OneFrameImageStreamCompleterCls(Future<ImageInfo> image, InformationCollector informationCollector);

private:

};
using OneFrameImageStreamCompleter = std::shared_ptr<OneFrameImageStreamCompleterCls>;

class MultiFrameImageStreamCompleterCls : public ImageStreamCompleterCls {
public:

     MultiFrameImageStreamCompleterCls(Stream<ImageChunkEvent> chunkEvents, Future<Codec> codec, String debugLabel, InformationCollector informationCollector, double scale);

    virtual void addListener(ImageStreamListener listener);

    virtual void removeListener(ImageStreamListener listener);

private:
    StreamSubscription<ImageChunkEvent> _chunkSubscription;

    Codec _codec;

    double _scale;

    InformationCollector _informationCollector;

    FrameInfo _nextFrame;

    Duration _shownTimestamp;

    Duration _frameDuration;

    int _framesEmitted;

    Timer _timer;

    bool _frameCallbackScheduled;


    virtual void _handleCodecReady(Codec codec);

    virtual void _handleAppFrame(Duration timestamp);

    virtual bool _isFirstFrame();

    virtual bool _hasFrameDurationPassed(Duration timestamp);

    virtual Future<void> _decodeNextFrameAndSchedule();

    virtual void _scheduleAppFrame();

    virtual void _emitFrame(ImageInfo imageInfo);

    virtual void _maybeDispose();

};
using MultiFrameImageStreamCompleter = std::shared_ptr<MultiFrameImageStreamCompleterCls>;


#endif