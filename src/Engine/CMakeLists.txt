cmake_minimum_required(VERSION 3.7)
project(Engine)
set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES src/Scene.cpp include/Scene.h src/GameObject.cpp include/GameObject.h src/PhysComponent.cpp include/PhysComponent.h src/Transform.cpp include/Transform.h src/Component.cpp include/Component.h src/SpriteComponent.cpp include/SpriteComponent.h src/GlobalInfo.cpp include/GlobalInfo.h src/Collider.cpp include/Collider.h src/CollisionManager.cpp include/CollisionManager.h src/AbstractManager.cpp include/AbstractManager.h src/CleanManager.cpp include/CleanManager.h include/helpFunctions.h src/CameraComponent.cpp include/CameraComponent.h)

add_library(Engine ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/..")

find_package(SFML COMPONENTS system window graphics REQUIRED)

target_link_libraries(Engine ${SFML_LIBRARIES})
