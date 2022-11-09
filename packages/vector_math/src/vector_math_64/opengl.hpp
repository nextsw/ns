#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_OPENGL
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_OPENGL
#include <base.hpp>

#include <dart/core/core.hpp>

void setRotationMatrix(Vector3 forwardDirection, Matrix4 rotationMatrix, Vector3 upDirection);

void setModelMatrix(Vector3 forwardDirection, Matrix4 modelMatrix, double tx, double ty, double tz, Vector3 upDirection);

void setViewMatrix(Vector3 cameraFocusPosition, Vector3 cameraPosition, Vector3 upDirection, Matrix4 viewMatrix);

Matrix4 makeViewMatrix(Vector3 cameraFocusPosition, Vector3 cameraPosition, Vector3 upDirection);

void setPerspectiveMatrix(double aspectRatio, double fovYRadians, Matrix4 perspectiveMatrix, double zFar, double zNear);

Matrix4 makePerspectiveMatrix(double aspectRatio, double fovYRadians, double zFar, double zNear);

void setInfiniteMatrix(double aspectRatio, double fovYRadians, Matrix4 infiniteMatrix, double zNear);

Matrix4 makeInfiniteMatrix(double aspectRatio, double fovYRadians, double zNear);

void setFrustumMatrix(double bottom, double far, double left, double near, Matrix4 perspectiveMatrix, double right, double top);

Matrix4 makeFrustumMatrix(double bottom, double far, double left, double near, double right, double top);

void setOrthographicMatrix(double bottom, double far, double left, double near, Matrix4 orthographicMatrix, double right, double top);

Matrix4 makeOrthographicMatrix(double bottom, double far, double left, double near, double right, double top);

Matrix4 makePlaneProjection(Vector3 planeNormal, Vector3 planePoint);

Matrix4 makePlaneReflection(Vector3 planeNormal, Vector3 planePoint);

bool unproject(Matrix4 cameraMatrix, Vector3 pickWorld, num pickX, num pickY, num pickZ, num viewportHeight, num viewportWidth, num viewportX, num viewportY);

bool pickRay(Matrix4 cameraMatrix, num pickX, num pickY, Vector3 rayFar, Vector3 rayNear, num viewportHeight, num viewportWidth, num viewportX, num viewportY);



#endif