#include "Sprite.h"
#include "../../Core/CoreEngine.h"
Sprite::Sprite(GLuint shaderProgram_, const std::string& textureName_) : depth(0)
{
    shaderProgram = shaderProgram_;
   //textureTag = textureName_;
    TextureHandler::GetInstance()->InitTexture(textureName_);
    spriteRender = new SpriteRenderer(textureName_, shaderProgram);

    //TODO:improve this, it is 
    box = BoundingBox(TextureHandler::GetInstance()->GetTextureData(textureName_)->spriteWidth,
        TextureHandler::GetInstance()->GetTextureData(textureName_)->spriteHeight,
        glm::mat4(0));
    SceneGraph::GetInstance()->AddSprite(this);


    
}

Sprite::~Sprite()
{
}

const int Sprite::CreateInstance(glm::vec3 position_, float rotation_, glm::vec3 scale_)
{
    spriteInstances.push_back(GetTransform(position_, rotation_, scale_));
    return spriteInstances.size() - 1;
}

void Sprite::UpdateInstance(int index_, glm::vec3 position_, float rotation_, glm::vec3 scale_)
{
    spriteInstances[index_] = GetTransform(position_, rotation_, scale_);
}

BoundingBox Sprite::GetBoundingBox()
{
    return box;
}

glm::mat4 Sprite::GetTransform(int index_) const
{
    return spriteInstances[index_];
}


GLuint Sprite::GetShaderProgram() const
{
    return shaderProgram;
}

glm::mat4 Sprite::GetTransform(glm::vec3 position_, float rotation_, glm::vec3 scale_) const
{
    glm::mat4 model = glm::mat4(1.0f);

    model = glm::translate(model, position_);

    //TODO: this might not work well/may cause serious issues, however it might be a performance improvement due to skiping on 
    //usless steps
    if (rotation_ != 0) {
        model = glm::translate(model, glm::vec3(0.5f * scale_.x, 0.5f * scale_.y, 0.0f)); // move origin of rotation to center of quad
        model = glm::rotate(model, glm::radians(rotation_ + 180), glm::vec3(0.0f, 0.0f, 1.0f)); // rotate
        model = glm::translate(model, glm::vec3(-0.5f * scale_.x, -0.5f * scale_.y, 0.0f)); // move origin back
    }
    model = glm::scale(model, scale_);

    return model;
}

void Sprite::Render(Camera* camera_)
{
    spriteRender->Render(camera_, spriteInstances);
    //Could this system have worked? mabye look into blend for thesprite sheet parse
   // glEnable(GL_TEXTURE_2D);
   // glEnable(GL_BLEND);
   // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    //GL Proejction
    //GL othertographic
    //gl model view

    //TODO: try and fix the fact that the image is not showing up, though alot of other work has been completed

}