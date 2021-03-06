#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <glm/glm.hpp>

struct BoundingBox {
public:
	float width, height;
	glm::mat4 transform;

	inline BoundingBox() {
		width = 0;
		height = 0;
		transform = glm::mat4();
	}

	inline BoundingBox(float width_, float height_, glm::mat4 transform_) {
		width = width_;
		height = height_;
		transform = transform_;
	}

	//TODO: need to change this in order for collision to work
	inline bool Intersects(BoundingBox* box_) {
		//glm::vec3 minCorner = GetTransformedPoint(minVert, transform);
		//glm::vec3 maxCorner = GetTransformedPoint(maxVert, transform);

		//glm::vec3 otherMinCorner = GetTransformedPoint(box_->minVert, box_->transform);
		//glm::vec3 otherMaxCorner = GetTransformedPoint(box_->maxVert, box_->transform);
		
		//if (minCorner.x <= otherMaxCorner.x && maxCorner.x >= otherMinCorner.x &&
		//	minCorner.y <= otherMaxCorner.y && maxCorner.y >= otherMinCorner.y) {
		//	return true;
		//}

		return false;
	}

private:
	//Possible error for the transform, yes 2d objects have transforms
	inline glm::vec3 GetTransformedPoint(glm::vec3 point_, glm::mat4 transform_) {
		return glm::vec3(transform_[3].x, transform_[3].y,transform_[3].z) + point_;
	}
};


#endif // !BOUNDINGBOX_H
