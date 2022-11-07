#include "opengl.hpp"
void setRotationMatrix(Vector3 forwardDirection, Matrix4 rotationMatrix, Vector3 upDirection) {
    setModelMatrix(rotationMatrix, forwardDirection, upDirection, 0.0, 0.0, 0.0);
}

void setModelMatrix(Vector3 forwardDirection, Matrix4 modelMatrix, double tx, double ty, double tz, Vector3 upDirection) {
    Unknown right = ;
    Unknown c1 = right;
    Unknown c2 = upDirection;
    Unknown c3 = -forwardDirection;
    modelMatrix.setValues(c1[0], c1[1], c1[2], 0.0, c2[0], c2[1], c2[2], 0.0, c3[0], c3[1], c3[2], 0.0, tx, ty, tz, 1.0);
}

void setViewMatrix(Vector3 cameraFocusPosition, Vector3 cameraPosition, Vector3 upDirection, Matrix4 viewMatrix) {
    Unknown z = ;
    Unknown x = ;
    Unknown y = ;
    Unknown rotatedEyeX = -x.dot(cameraPosition);
    Unknown rotatedEyeY = -y.dot(cameraPosition);
    Unknown rotatedEyeZ = -z.dot(cameraPosition);
    viewMatrix.setValues(x[0], y[0], z[0], 0.0, x[1], y[1], z[1], 0.0, x[2], y[2], z[2], 0.0, rotatedEyeX, rotatedEyeY, rotatedEyeZ, 1.0);
}

Matrix4 makeViewMatrix(Vector3 cameraFocusPosition, Vector3 cameraPosition, Vector3 upDirection) {
    Unknown r = Matrix4.zero();
    setViewMatrix(r, cameraPosition, cameraFocusPosition, upDirection);
    return r;
}

void setPerspectiveMatrix(double aspectRatio, double fovYRadians, Matrix4 perspectiveMatrix, double zFar, double zNear) {
    Unknown height = math.tan(fovYRadians * 0.5);
    Unknown width = height * aspectRatio;
    Unknown near_minus_far = zNear - zFar;
    ;
}

Matrix4 makePerspectiveMatrix(double aspectRatio, double fovYRadians, double zFar, double zNear) {
    Unknown r = Matrix4.zero();
    setPerspectiveMatrix(r, fovYRadians, aspectRatio, zNear, zFar);
    return r;
}

void setInfiniteMatrix(double aspectRatio, double fovYRadians, Matrix4 infiniteMatrix, double zNear) {
    Unknown height = math.tan(fovYRadians * 0.5);
    Unknown width = height * aspectRatio;
    ;
}

Matrix4 makeInfiniteMatrix(double aspectRatio, double fovYRadians, double zNear) {
    Unknown r = Matrix4.zero();
    setInfiniteMatrix(r, fovYRadians, aspectRatio, zNear);
    return r;
}

void setFrustumMatrix(double bottom, double far, double left, double near, Matrix4 perspectiveMatrix, double right, double top) {
    Unknown two_near = 2.0 * near;
    Unknown right_minus_left = right - left;
    Unknown top_minus_bottom = top - bottom;
    Unknown far_minus_near = far - near;
    ;
}

Matrix4 makeFrustumMatrix(double bottom, double far, double left, double near, double right, double top) {
    Unknown view = Matrix4.zero();
    setFrustumMatrix(view, left, right, bottom, top, near, far);
    return view;
}

void setOrthographicMatrix(double bottom, double far, double left, double near, Matrix4 orthographicMatrix, double right, double top) {
    Unknown rml = right - left;
    Unknown rpl = right + left;
    Unknown tmb = top - bottom;
    Unknown tpb = top + bottom;
    Unknown fmn = far - near;
    Unknown fpn = far + near;
    ;
}

Matrix4 makeOrthographicMatrix(double bottom, double far, double left, double near, double right, double top) {
    Unknown r = Matrix4.zero();
    setOrthographicMatrix(r, left, right, bottom, top, near, far);
    return r;
}

Matrix4 makePlaneProjection(Vector3 planeNormal, Vector3 planePoint) {
    Unknown v = Vector4(planeNormal.storage[0], planeNormal.storage[1], planeNormal.storage[2], 0.0);
    Unknown outer = Matrix4.outer(v, v);
    auto r = Matrix4.zero();
    r = r - outer;
    Unknown scaledNormal = planeNormal.scaled(dot3(planePoint, planeNormal));
    Unknown T = Vector4(scaledNormal.storage[0], scaledNormal.storage[1], scaledNormal.storage[2], 1.0);
    r.setColumn(3, T);
    return r;
}

Matrix4 makePlaneReflection(Vector3 planeNormal, Vector3 planePoint) {
    Unknown v = Vector4(planeNormal.storage[0], planeNormal.storage[1], planeNormal.storage[2], 0.0);
    Unknown outer = ;
    auto r = Matrix4.zero();
    r = r - outer;
    Unknown scale = 2.0 * planePoint.dot(planeNormal);
    Unknown scaledNormal = planeNormal.scaled(scale);
    Unknown T = Vector4(scaledNormal.storage[0], scaledNormal.storage[1], scaledNormal.storage[2], 1.0);
    r.setColumn(3, T);
    return r;
}

bool unproject(Matrix4 cameraMatrix, Vector3 pickWorld, num pickX, num pickY, num pickZ, num viewportHeight, num viewportWidth, num viewportX, num viewportY) {
    viewportX = viewportX.toDouble();
    viewportWidth = viewportWidth.toDouble();
    viewportY = viewportY.toDouble();
    viewportHeight = viewportHeight.toDouble();
    pickX = pickX.toDouble();
    pickY = pickY.toDouble();
    pickX = pickX - viewportX;
    pickY = pickY - viewportY;
    pickX = (2.0 * pickX / viewportWidth) - 1.0;
    pickY = (2.0 * pickY / viewportHeight) - 1.0;
    pickZ = (2.0 * pickZ) - 1.0;
    if ( < -1.0 ||  < -1.0 || pickX > 1.0 || pickY > 1.0 ||  < -1.0 || pickZ > 1.0) {
        return false;
    }
    Unknown invertedCameraMatrix = Matrix4.copy(cameraMatrix);
    invertedCameraMatrix.invert();
    Unknown v = Vector4(pickX.toDouble(), pickY.toDouble(), pickZ.toDouble(), 1.0);
    invertedCameraMatrix.transform(v);
    if (v.w == 0.0) {
        return false;
    }
    Unknown invW = 1.0 / v.w;
    ;
    return true;
}

bool pickRay(Matrix4 cameraMatrix, num pickX, num pickY, Vector3 rayFar, Vector3 rayNear, num viewportHeight, num viewportWidth, num viewportX, num viewportY) {
    bool r;
    r = unproject(cameraMatrix, viewportX, viewportWidth, viewportY, viewportHeight, pickX, viewportHeight - pickY, 0.0, rayNear);
    if (!r) {
        return false;
    }
    return unproject(cameraMatrix, viewportX, viewportWidth, viewportY, viewportHeight, pickX, viewportHeight - pickY, 1.0, rayFar);
}
