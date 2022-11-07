#ifndef IMAGE_STREAM_H
#define IMAGE_STREAM_H
#include <memory>

#include <async/async.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/scheduler.hpp>



class ImageInfo {
public:
    Image image;

    double scale;

    String debugLabel;


     ImageInfo(String debugLabel, Image image, double scale);

    ImageInfo clone();

    bool isCloneOf(ImageInfo other);

    int sizeBytes();

    void dispose();

    String toString();

    int hashCode();

    bool ==(Object other);

private:

};

class ImageStreamListener {
public:
    ImageListener onImage;

    ImageChunkListener onChunk;

    ImageErrorListener onError;


     ImageStreamListener(ImageChunkListener onChunk, ImageErrorListener onError, ImageListener onImage);

    int hashCode();

    bool ==(Object other);

private:

};

class ImageChunkEvent {
public:
    int cumulativeBytesLoaded;

    int expectedTotalBytes;


     ImageChunkEvent(int cumulativeBytesLoaded, int expectedTotalBytes);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class ImageStream {
public:

     ImageStream();

    ImageStreamCompleter completer();

    void setCompleter(ImageStreamCompleter value);

    void addListener(ImageStreamListener listener);

    void removeListener(ImageStreamListener listener);

    Object key();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    ImageStreamCompleter _completer;

    List<ImageStreamListener> _listeners;


};

class ImageStreamCompleterHandle {
public:

    void dispose();

private:
    ImageStreamCompleter _completer;


    void  _(ImageStreamCompleter _completer);

};

class ImageStreamCompleter {
public:
    String debugLabel;


    bool hasListeners();

    void addListener(ImageStreamListener listener);

    ImageStreamCompleterHandle keepAlive();

    void removeListener(ImageStreamListener listener);

    void addOnLastListenerRemovedCallback(VoidCallback callback);

    void removeOnLastListenerRemovedCallback(VoidCallback callback);

    void setImage(ImageInfo image);

    void reportError(DiagnosticsNode context, Object exception, InformationCollector informationCollector, bool silent, StackTrace stack);

    void reportImageChunkEvent(ImageChunkEvent event);

    void debugFillProperties(DiagnosticPropertiesBuilder description);

private:
    List<ImageStreamListener> _listeners;

    ImageInfo _currentImage;

    FlutterErrorDetails _currentError;

    bool _hadAtLeastOneListener;

    bool _addingInitialListeners;

    int _keepAliveHandles;

    bool _disposed;

    List<VoidCallback> _onLastListenerRemovedCallbacks;


    void _maybeDispose();

    void _checkDisposed();

};

class OneFrameImageStreamCompleter : ImageStreamCompleter {
public:

     OneFrameImageStreamCompleter(Future<ImageInfo> image, InformationCollector informationCollector);

private:

};

class MultiFrameImageStreamCompleter : ImageStreamCompleter {
public:

     MultiFrameImageStreamCompleter(Stream<ImageChunkEvent> chunkEvents, Future<Codec> codec, String debugLabel, InformationCollector informationCollector, double scale);

    void addListener(ImageStreamListener listener);

    void removeListener(ImageStreamListener listener);

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


    void _handleCodecReady(Codec codec);

    void _handleAppFrame(Duration timestamp);

    bool _isFirstFrame();

    bool _hasFrameDurationPassed(Duration timestamp);

    Future<void> _decodeNextFrameAndSchedule();

    void _scheduleAppFrame();

    void _emitFrame(ImageInfo imageInfo);

    void _maybeDispose();

};

#endif