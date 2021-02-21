#include "SDL.hpp"


SDL::SDL()
{
    int imgFlags = (IMG_INIT_JPG | IMG_INIT_PNG);
    int initted;

    // SDL Initialization
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0 ) {
		std::cerr << "SDL could not initialize! SDL Error: "
            << SDL_GetError() << std::endl;
		exit(84);
	}

    //Set texture filtering to linear
    if(!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        std::cout << "Warning: Linear texture filtering not enabled!" << std::endl;

    // SDL Image Initialization
    initted = IMG_Init(imgFlags);
    if((initted & imgFlags) != imgFlags) {
        std::cout << "SDL_image could not initialize! SDL_image Error: "
            << IMG_GetError() << std::endl;
        exit(84);
    }

    // SDL TTF Initialization
    if(TTF_Init() == -1) {
        std::cout << "SDL_ttf could not initialize! SDL_ttf Error: "
            << TTF_GetError() << std::endl;
        exit(84);
    }
}

SDL::~SDL()
{
    // Quit the SDL Subsystems
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void SDL::createWindow(int x, int y)
{
    // Window Creation
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, x, y, SDL_WINDOW_SHOWN);
    if (_window == nullptr) {
        std::cerr << "Window could not be created! SDL Error: "
            << SDL_GetError() << std::endl;
        exit(84);
    }

    // Window Renderer Creation
    _windowR = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED );
	if(_windowR == nullptr) {
        std::cout << "Renderer could not be created! SDL Error: "
            << SDL_GetError() << std::endl;
        exit(84);
    }

    // Initialize Renderer color
    SDL_SetRenderDrawColor(_windowR, 0x0, 0x0, 0x0, 0xFF);
}

void SDL::deleteWindow(void)
{
    // Destroy loaded textures
    for (auto map : _textures)
        SDL_DestroyTexture(map.second);

    //Destroy window and its renderer
	SDL_DestroyRenderer(_windowR);
    SDL_DestroyWindow(_window);
}

bool SDL::initSprites(const std::vector<core::GameObject> &objs)
{
    SDL_Texture *texture = nullptr;
    TTF_Font* font = TTF_OpenFont("arcade.ttf", 14);

    if(!font) {
        std::cerr << "Unable to load font " << "arcade.ttf"
            << "! TTF_OpenFont: " << TTF_GetError() << std::endl;
    }
    _font = font;
    for (auto elem : objs) {
        if (elem._type == core::IMAGE) {
            SDL_Surface* loadedSurface = IMG_Load(elem._name.c_str());
            if (loadedSurface == nullptr) {
                std::cerr << "Unable to load image " << elem._name
                    << "! SDL_image Error: " << IMG_GetError() << std::endl;
                exit(84);
            }
            texture = SDL_CreateTextureFromSurface(_windowR, loadedSurface);
            if (texture == nullptr) {
                std::cerr << "Unable to load texture from " << elem._name
                    << "! SDL Error: " << SDL_GetError() << std::endl;
                exit(84);
            }
            SDL_FreeSurface(loadedSurface);
            _textures.emplace(elem._name, texture);
        }
    }
    return true;
}

bool SDL::updateGraphics(const std::vector<core::GameObject> &objects)
{
    // Clear content from the screen and repaint using the default colour
    SDL_RenderClear(_windowR);
    for (auto elem : objects) {
        if (elem._type == core::IMAGE) {
            for (auto map : _textures) {
                if (map.first == elem._name) {
                    SDL_Rect src = {
                        .x = elem._originX,
                        .y = elem._originY,
                        .w = elem._width,
                        .h = elem._height
                    };
                    SDL_Rect dest = {
                        .x = elem._posX,
                        .y = elem._posY,
                        .w = elem._width,
                        .h = elem._height
                    };

                    // Render scales texture to the screen
                    SDL_RenderCopy(_windowR, map.second, &src, &dest);
                    break;
                }
            }
        }
    }
    for (auto elem : objects) {
        if (elem._type == core::TEXT) {
            SDL_Color red = {255, 0, 0, 255};
            SDL_Surface *messageS = TTF_RenderText_Solid(_font, elem._text.c_str(), red);
            if (messageS == nullptr) {
                std::cerr << "Unable to render text \"" << elem._name
                    << "\"! SDL_image Error: " << TTF_GetError() << std::endl;
                exit(84);
            }
            SDL_Rect dest = {
                .x = elem._posX,
                .y = elem._posY,
                .w = messageS->w,
                .h = messageS->h
            };
            SDL_Texture *messageT = SDL_CreateTextureFromSurface(_windowR, messageS);
            if (messageT == nullptr) {
                std::cerr << "Unable to load texture from " << elem._name
                    << "! SDL Error: " << SDL_GetError() << std::endl;
                exit(84);
            }
            SDL_RenderCopy(_windowR, messageT, NULL, &dest);
            SDL_FreeSurface(messageS);
            SDL_DestroyTexture(messageT);
        }
    }

    // Update the screen
    SDL_RenderPresent(_windowR);
    return true;
}

std::vector<core::Event> SDL::eventLoop()
{
    std::vector<core::Event> vecEvents;
    SDL_Event event;

    // Handle events in queue
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            vecEvents.push_back(core::QUIT);
        else if (event.type == SDL_KEYDOWN){
            switch (event.key.keysym.sym){
                case (SDLK_z) : vecEvents.push_back(core::UP);
                    break;
                case (SDLK_q) : vecEvents.push_back(core::LEFT);
                    break;
                case (SDLK_s) : vecEvents.push_back(core::DOWN);
                    break;
                case (SDLK_d) : vecEvents.push_back(core::RIGHT);
                    break;
                case (SDLK_j) : vecEvents.push_back(core::SHOOT);
                    break;
                case (SDLK_RETURN) : vecEvents.push_back(core::ENTER);
                    break;
                case (SDLK_p) : vecEvents.push_back(core::PAUSE);
                    break;
                case (SDLK_r) : vecEvents.push_back(core::RESTART);
                    break;
                case (SDLK_ESCAPE) : vecEvents.push_back(core::QUIT);
                    break;
                case (SDLK_RIGHT) : vecEvents.push_back(core::NEXT_GRAPH);
                    break;
                case (SDLK_LEFT) : vecEvents.push_back(core::PREV_GRAPH);
                    break;
                case (SDLK_DOWN) : vecEvents.push_back(core::PREV_GAME);
                    break;
                case (SDLK_UP) : vecEvents.push_back(core::NEXT_GAME);
                    break;
                default : break;
            }
        }
    }
    return vecEvents;
}

extern "C" std::unique_ptr<SDL>getInstance(void)
{
    return std::make_unique<SDL>();
}
