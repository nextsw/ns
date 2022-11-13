#include "shader_warm_up.hpp"
Size ShaderWarmUpCls::size() {
    return ui->make<SizeCls>(100.0, 100.0);
}

Future<void> ShaderWarmUpCls::execute() {
    PictureRecorder recorder = ui->make<PictureRecorderCls>();
    Canvas canvas = ui->make<CanvasCls>(recorder);
    await warmUpOnCanvas(canvas);
    Picture picture = recorder->endRecording();
    assert(debugCaptureShaderWarmUpPicture(picture));
    if (!kIsWeb) {
        TimelineTask shaderWarmUpTask = make<TimelineTaskCls>();
        shaderWarmUpTask->start(__s("Warm-up shader"));
        try {
            Image image = await picture->toImage(size()->width()->ceil(), size()->height()->ceil());
            assert(debugCaptureShaderWarmUpImage(image));
            image->dispose();
        } finally {
            shaderWarmUpTask->finish();
        };
    }
    picture->dispose();
}
