#include "opengl.hpp"
void setRotationMatrix(Vector3 forwardDirection, Matrix4 rotationMatrix, Vector3 upDirection) {
    setModelMatrix(rotationMatrix, forwardDirection, upDirection, 0.0, 0.0, 0.0);
}

void setModelMatrix(Vector3 forwardDirection, Matrix4 modelMatrix, double tx, double ty, double tz, Vector3 upDirection) {
    auto _c1 = forwardDirection->cross(upDirection);_c1.normalize();Unknown right = _c1;
    Unknown c1 = right;
    Unknown c2 = upDirection;
    Unknown c3 = -forwardDirection;
    modelMatrix->setValues(c1[0], c1[1], c1[2], 0.0, c2[0], c2[1], c2[2], 0.0, c3[0], c3[1], c3[2], 0.0, tx, ty, tz, 1.0);
}

void setViewMatrix(Vector3 cameraFocusPosition, Vector3 cameraPosition, Vector3 upDirection, Matrix4 viewMatrix) {
    auto _c1 = (cameraPosition - cameraFocusPosition);_c1.normalize();Unknown z = _c1;
    auto _c2 = upDirection->cross(z);_c2.normalize();Unknown x = _c2;
    auto _c3 = z->cross(x);_c3.normalize();Unknown y = _c3;
    Unknown rotatedEyeX = -x->dot(cameraPosition);
    Unknown rotatedEyeY = -y->dot(cameraPosition);
    Unknown rotatedEyeZ = -z->dot(cameraPosition);
    viewMatrix->setValues(x[0], y[0], z[0], 0.0, x[1], y[1], z[1], 0.0, x[2], y[2], z[2], 0.0, rotatedEyeX, rotatedEyeY, rotatedEyeZ, 1.0);
}

Matrix4 makeViewMatrix(Vector3 cameraFocusPosition, Vector3 cameraPosition, Vector3 upDirection) {
    Unknown r = Matrix4Cls->zero();
    setViewMatrix(r, cameraPosition, cameraFocusPosition, upDirection);
    return r;
}

void setPerspectiveMatrix(double aspectRatio, double fovYRadians, Matrix4 perspectiveMatrix, double zFar, double zNear) {
    Unknown height = math->tan(fovYRadians * 0.5);
    Unknown width = height * aspectRatio;
    Unknown near_minus_far = zNear - zFar;
    auto _c1 = perspectiveMatrix;_c1.auto _c2 = setZero();_c2.auto _c3 = setEntry(0, 0, 1.0 / width);_c3.auto _c4 = setEntry(1, 1, 1.0 / height);_c4.auto _c5 = setEntry(2, 2, (zFar + zNear) / near_minus_far);_c5.auto _c6 = setEntry(3, 2, -1.0);_c6.setEntry(2, 3, (2.0 * zNear * zFar) / near_minus_far);_c6;_c5;_c4;_c3;_c2;_c1;
}

Matrix4 makePerspectiveMatrix(double aspectRatio, double fovYRadians, double zFar, double zNear) {
    Unknown r = Matrix4Cls->zero();
    setPerspectiveMatrix(r, fovYRadians, aspectRatio, zNear, zFar);
    return r;
}

void setInfiniteMatrix(double aspectRatio, double fovYRadians, Matrix4 infiniteMatrix, double zNear) {
    Unknown height = math->tan(fovYRadians * 0.5);
    Unknown width = height * aspectRatio;
    auto _c1 = infiniteMatrix;_c1.auto _c2 = setZero();_c2.auto _c3 = setEntry(0, 0, 1.0 / width);_c3.auto _c4 = setEntry(1, 1, 1.0 / height);_c4.auto _c5 = setEntry(2, 2, -1.0);_c5.auto _c6 = setEntry(3, 2, -1.0);_c6.setEntry(2, 3, -2.0 * zNear);_c6;_c5;_c4;_c3;_c2;_c1;
}

Matrix4 makeInfiniteMatrix(double aspectRatio, double fovYRadians, double zNear) {
    Unknown r = Matrix4Cls->zero();
    setInfiniteMatrix(r, fovYRadians, aspectRatio, zNear);
    return r;
}

void setFrustumMatrix(double bottom, double far, double left, double near, Matrix4 perspectiveMatrix, double right, double top) {
    Unknown two_near = 2.0 * near;
    Unknown right_minus_left = right - left;
    Unknown top_minus_bottom = top - bottom;
    Unknown far_minus_near = far - near;
    auto _c1 = perspectiveMatrix;_c1.auto _c2 = setZero();_c2.auto _c3 = setEntry(0, 0, two_near / right_minus_left);_c3.auto _c4 = setEntry(1, 1, two_near / top_minus_bottom);_c4.auto _c5 = setEntry(0, 2, (right + left) / right_minus_left);_c5.auto _c6 = setEntry(1, 2, (top + bottom) / top_minus_bottom);_c6.auto _c7 = setEntry(2, 2, -(far + near) / far_minus_near);_c7.auto _c8 = setEntry(3, 2, -1.0);_c8.setEntry(2, 3, -(two_near * far) / far_minus_near);_c8;_c7;_c6;_c5;_c4;_c3;_c2;_c1;
}

Matrix4 makeFrustumMatrix(double bottom, double far, double left, double near, double right, double top) {
    Unknown view = Matrix4Cls->zero();
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
    auto _c1 = orthographicMatrix;_c1.auto _c2 = setZero();_c2.auto _c3 = setEntry(0, 0, 2.0 / rml);_c3.auto _c4 = setEntry(1, 1, 2.0 / tmb);_c4.auto _c5 = setEntry(2, 2, -2.0 / fmn);_c5.auto _c6 = setEntry(0, 3, -rpl / rml);_c6.auto _c7 = setEntry(1, 3, -tpb / tmb);_c7.auto _c8 = setEntry(2, 3, -fpn / fmn);_c8.setEntry(3, 3, 1.0);_c8;_c7;_c6;_c5;_c4;_c3;_c2;_c1;
}

Matrix4 makeOrthographicMatrix(double bottom, double far, double left, double near, double right, double top) {
    Unknown r = Matrix4Cls->zero();
    setOrthographicMatrix(r, left, right, bottom, top, near, far);
    return r;
}

Matrix4 makePlaneProjection(Vector3 planeNormal, Vector3 planePoint) {
    Unknown v = make<Vector4Cls>(planeNormal->storage()[0], planeNormal->storage()[1], planeNormal->storage()[2], 0.0);
    Unknown outer = Matrix4Cls->outer(v, v);
    auto r = Matrix4Cls->zero();
    r = r - outer;
    Unknown scaledNormal = planeNormal->scaled(dot3(planePoint, planeNormal));
    Unknown T = make<Vector4Cls>(scaledNormal->storage()[0], scaledNormal->storage()[1], scaledNormal->storage()[2], 1.0);
    r->setColumn(3, T);
    return r;
}

Matrix4 makePlaneReflection(Vector3 planeNormal, Vector3 planePoint) {
    Unknown v = make<Vector4Cls>(planeNormal->storage()[0], planeNormal->storage()[1], planeNormal->storage()[2], 0.0);
    auto _c1 = Matrix4Cls->outer(v, v);_c1.scale(2.0);Unknown outer = _c1;
    auto r = Matrix4Cls->zero();
    r = r - outer;
    Unknown scale = 2.0 * planePoint->dot(planeNormal);
    Unknown scaledNormal = planeNormal->scaled(scale);
    Unknown T = make<Vector4Cls>(scaledNormal->storage()[0], scaledNormal->storage()[1], scaledNormal->storage()[2], 1.0);
    r->setColumn(3, T);
    return r;
}

bool unproject(Matrix4 cameraMatrix, Vector3 pickWorld, num pickX, num pickY, num pickZ, num viewportHeight, num viewportWidth, num viewportX, num viewportY) {
    viewportX = viewportX->toDouble();
    viewportWidth = viewportWidth->toDouble();
    viewportY = viewportY->toDouble();
    viewportHeight = viewportHeight->toDouble();
    pickX = pickX->toDouble();
    pickY = pickY->toDouble();
    pickX = pickX - viewportX;
    pickY = pickY - viewportY;
    pickX = (2.0 * pickX / viewportWidth) - 1.0;
    pickY = (2.0 * pickY / viewportHeight) - 1.0;
    pickZ = (2.0 * pickZ) - 1.0;
    if ( < -1.0 ||  < -1.0 || pickX > 1.0 || pickY > 1.0 ||  < -1.0 || pickZ > 1.0) {
        return false;
    }
    Unknown invertedCameraMatrix = Matrix4Cls->copy(cameraMatrix);
    invertedCameraMatrix->invert();
    Unknown v = make<Vector4Cls>(pickX->toDouble(), pickY->toDouble(), pickZ->toDouble(), 1.0);
    invertedCameraMatrix->transform(v);
    if (v->w == 0.0) {
        return false;
    }
    Unknown invW = 1.0 / v->w;
    auto _c1 = pickWorld;_c1.x = auto _c2 = v->x * invW;_c2.y = auto _c3 = v->y * invW;_c3.z = v->z * invW;_c3;_c2;_c1;
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
