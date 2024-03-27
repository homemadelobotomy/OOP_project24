#include "proj.h"

void proj::initVariables()
{
    this->window = nullptr;
    this->maxBlock = 16;
    float blockPosY = 10.f;
    this->bullet.setSize(sf::Vector2f(8.f,8.f));
    this->bullet.setFillColor(sf::Color::Red);
    this->bullet.setPosition(600.f / 2.f - this->bullet.getSize().x / 2.f,
                             600.f - this->bullet.getSize().y * 10.f); 
    this->platform.setSize(sf::Vector2f(120.f,15.f));
    this->platform.setFillColor(sf::Color::White);
     this->platform.setPosition(600.f/2 - this->platform.getSize().x / 2, 600.f - 2*this->platform.getSize().y);
          
                  
}

void proj::initWindow(){
    this->videoMode.height = 600;
    this->videoMode.width = 600;
    
    this->window = new sf::RenderWindow(this->videoMode,"project", sf::Style::Titlebar | sf::Style::Close);
    
    this->window->setFramerateLimit(60);
}

void proj::initBlocks(){
    this->block.setSize(sf::Vector2f(100.f,10.f));
    this->block.setFillColor(sf::Color::White);
    this->block.setPosition(10.f,10.f);
}

proj::proj()
{   
    this->initVariables();
    this->initBlocks();
    this->initWindow();
    
}


proj::~proj()
{
    delete this->window;
} 

void proj::pollEvents(){
    while(this->window->pollEvent(this->ev)){
        switch (ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;

        case sf::Event::KeyPressed:
            if(this->ev.key.code == sf::Keyboard::Escape){
                this->window->close();
            }
            if (this->ev.key.code == sf::Keyboard::Enter){
                
                velocity.x = (rand() % 3 + 3) * 0.1f;
                velocity.y = (rand() % 3 + 3) * 0.1f;


            }
            break;
        
        
        default:
            break;
        }
    }
}

const bool proj::running()
{
    return this->window->isOpen();
}

void proj::renderBlocks(){
    int j = 0;
    for (size_t i = 0; i < this->maxBlock; i++)
    {   
        
        if (i % 4 == 0){
            this->blockPosY += this->block.getSize().y + 20.f;
            j = 0;
        }
        this->block.setPosition(j * (this->block.getSize().x + 40.f) + 10.f, this->blockPosY);
        this->blocks.push_back(this->block);
        this->window->draw(this->blocks[i]);
        j++;

    }
    

}
void proj::update(){
    this->pollEvents();
    this->renderBlocks();
    

    this->updateBullet();
    
    this->updateMousePos();
}
void proj::setUI(){
    this->button.setSize(sf::Vector2f(200.f,100.f));
    this->button.setFillColor(sf::Color::White);
    this->button.setPosition(0,500);
    this->button.setOutlineColor(sf::Color::Black);
    this->button.setOutlineThickness(1.f);
    
    if (!font.loadFromFile("proj/ofont.ru_Marker Felt.ttf")){
        throw "Erorr";
    }
    this->buttonText.setFont(font);
    this->buttonText.setCharacterSize(20);
    this->buttonText.setString(text);
    this->buttonText.setFillColor(sf::Color::Black);
    this->buttonText.setPosition(this->button.getPosition().x + 5,
                           this->button.getPosition().y + this->button.getSize().y /2);
}

void proj::updateMousePos(){
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
float dotProduct(const sf::Vector2f &a, const sf::Vector2f &b){
    
    return (a.x * b.x) + (a.y * b.y);
}

void proj::updatePlatform(){
   
    for(int i = 0; i < 16 ; i++){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            
            this->platform.move(-0.5f,0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            
            this->platform.move(0.5f,0);
        }
        if (this->platform.getPosition().x <= 0){
            this->platform.setPosition(0,this->videoMode.height - this->platform.getSize().y *2);
        }
        if (this->platform.getPosition().x + this->platform.getSize().x >= this->window->getSize().x){
            this->platform.setPosition(this->window->getSize().x - this->platform.getSize().x,this->videoMode.height - this->platform.getSize().y *2);
        }
    }
}
void proj::updateBullet(){
    
    this->updatePlatform();
    for (size_t i = 0; i < 16; i++)
    {
        //this->bullet.move(this->bulletSpeedX,this->bulletSpeedY);
        this->bullet.move(velocity);
        
        if(this->bullet.getPosition().x >= this->window->getSize().x - this->bullet.getSize().x ||
           this->bullet.getPosition().x <= 0){
            velocity.x = -velocity.x;
            //this->bulletSpeedX = -1 * this->bulletSpeedX ;
        }
        if(this->bullet.getPosition().y >= this->window->getSize().y - this->bullet.getSize().y ||
           this->bullet.getPosition().y <= 0){
            velocity.y = -velocity.y;
            //this->bulletSpeedY = -1 * this->bulletSpeedY ;
        }
    }
    

    for(int i = 0; i < maxBlock ;i++){
       
        if (this->bullet.getGlobalBounds().intersects(this->blocks[i].getGlobalBounds())){
            sf::Vector2f normal(0.f,0.f);
            if (this->bullet.getPosition().x < this->blocks[i].getPosition().x){
                normal.x = 1.f; 
            }
            else if (this->bullet.getPosition().x + this->bullet.getSize().x > this->blocks[i].getPosition().x + this->blocks[i].getSize().x){
                normal.x = -1.f;
            }
            if (this->bullet.getPosition().y < this->blocks[i].getPosition().y){
                normal.y = 1.f;
            }
            else if (this->bullet.getPosition().y + this->bullet.getSize().y > this->blocks[i].getPosition().y + this->blocks[i].getSize().y){
                normal.y = -1.f;
            }
            // std::cout << "Velocity before: " << velocity.x << " " << velocity.y << std::endl;
            // std::cout << "Normal: " << normal.x << " " << normal.y  << std::endl;
            // std::cout << "dotProduct = " << dotProduct(velocity,normal) << std::endl;
            if (std::abs(normal.x + normal.y) != 1){
                velocity.x = -velocity.x;
                velocity.y = -velocity.y;
            }
            else{
                velocity.x = velocity.x   -2.f * dotProduct(velocity,normal) * normal.x;
            velocity.y = velocity.y   -2.f * dotProduct(velocity,normal) * normal.y;
            }
            this->blocks.erase(this->blocks.begin() + i);
            this->maxBlock--;
            
            // std::cout << "Velocity after: " << velocity.x << " " << velocity.y << std::endl;
        }
        if (this->bullet.getPosition().x - 4.f > this->platform.getPosition().x &&
            this->bullet.getPosition().x + 4.f < this->platform.getPosition().x + this->platform.getSize().x &&
            this->bullet.getPosition().y + 8.f >= this->platform.getPosition().y){
            
            velocity.y = -velocity.y;
        }
        
    }
    
    
    
}

void proj::render(){

    this->window->clear();
    
    this->renderBlocks();
    this->window->draw(bullet);
    this->window->draw(platform);
    this->window->display();

}
