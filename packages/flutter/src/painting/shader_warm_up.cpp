#include "shader_warm_up.hpp"
Size ShaderWarmUp::size() {
    return const ui.Size(100.0, 100.0);
}

Future<void> ShaderWarmUp::execute() {
    PictureRecorder recorder = ui.PictureRecorder();
    Canvas canvas = ui.Canvas(recorder);
    await await warmUpOnCanvas(canvas);
    Picture picture = recorder.endRecording();
    assert(debugCaptureShaderWarmUpPicture(picture));
    if (!kIsWeb) {
        TimelineTask shaderWarmUpTask = TimelineTask();
        shaderWarmUpTask.start("Warm-up shader");
        ;
    }
    picture.dispose();
}
