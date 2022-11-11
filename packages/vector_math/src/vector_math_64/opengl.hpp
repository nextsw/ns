#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_OPENGL
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_OPENGL
#include <base.hpp>

#include <dart/core/core.hpp>

void setRotationMatrix(Matrix4 rotationMatrix, Vector3 forwardDirection, Vector3 upDirection);

void setModelMatrix(Matrix4 modelMatrix, Vector3 forwardDirection, Vector3 upDirection, double tx, double ty, double tz);

void setViewMatrix(Matrix4 viewMatrix, Vector3 cameraPosition, Vector3 cameraFocusPosition, Vector3 upDirection);

Matrix4 makeViewMatrix(Vector3 cameraPosition, Vector3 cameraFocusPosition, Vector3 upDirection);

void setPerspectiveMatrix(Matrix4 perspectiveMatrix, double fovYRadians, double aspectRatio, double zNear, double zFar);

Matrix4 makePerspectiveMatrix(double fovYRadians, double aspectRatio, double zNear, double zFar);

void setInfiniteMatrix(Matrix4 infiniteMatrix, double fovYRadians, double aspectRatio, double zNear);

Matrix4 makeInfiniteMatrix(double fovYRadians, double aspectRatio, double zNear);

void setFrustumMatrix(Matrix4 perspectiveMatrix, double left, double right, double bottom, double top, double near, double far);

Matrix4 makeFrustumMatrix(double left, double right, double bottom, double top, double near, double far);

void setOrthographicMatrix(Matrix4 orthographicMatrix, double left, double right, double bottom, double top, double near, double far);

Matrix4 makeOrthographicMatrix(double left, double right, double bottom, double top, double near, double far);

Matrix4 makePlaneProjection(Vector3 planeNormal, Vector3 planePoint);

Matrix4 makePlaneReflection(Vector3 planeNormal, Vector3 planePoint);

bool unproject(Matrix4 cameraMatrix, num viewportX, num viewportWidth, num viewportY, num viewportHeight, num pickX, num pickY, num pickZ, Vector3 pickWorld);

bool pickRay(Matrix4 cameraMatrix, num viewportX, num viewportWidth, num viewportY, num viewportHeight, num pickX, num pickY, Vector3 rayNear, Vector3 rayFar);



#endif