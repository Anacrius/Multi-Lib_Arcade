/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <string>
#include <dlfcn.h>

template<typename T>
class DLLoader {
    public:
        DLLoader(){};
        DLLoader(const std::string &path, const std::string &lib_name){
            _name = lib_name;
            _path = path + _name;
        };
        ~DLLoader(){};

        bool operator==(const DLLoader<T> &other){
            return _name == other._name && _path == other._path;
        }

        bool init(){
            _handle = dlopen(_path.c_str(), RTLD_LAZY);
            if (!_handle){
                return false;
            }
            //std::cout << "Open : " << _name << std::endl;
            return true;
        };

        void stop(){
            if (dlclose(_handle)){
                std::cerr << "dlclose failed: " << dlerror() << std::endl;
                exit(84);
            }
            //std::cout << "Close : " << _name << std::endl;
        };

        std::string &getName() {return _name;};
        std::string &getPath() {return _path;};
        std::unique_ptr<T> getInstance() {
            std::unique_ptr<T> (*fptr)(void);
            *(void **) (&fptr) = dlsym(_handle, "getInstance");
            char *error = dlerror();
            if (error){
                std::cerr << "dlsym failed: " << error << std::endl;
                exit(84);
            }
            return fptr();
        };

        bool testLib(){
            if (init()){
                std::unique_ptr<T> instance = getInstance();
                if (instance != NULL){
                    instance.release();
                    stop();
                    return true;
                }
                instance.release();
                stop();
            }
            return false;
        }

    protected:
    private:
        std::string _name;
        std::string _path;
        void *_handle;
};

#endif /* !DLLOADER_HPP_ */