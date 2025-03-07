cmake_minimum_required(VERSION 3.28)
project(Memory_MatchCard_Game)

set(CMAKE_CXX_STANDARD 17)


# Find wxWidgets

# Include wxWidgets use file


# Add source files
set(SRCS main.cpp Card.h Deck.h Player.h Game.h StandardCard.h BonusCard.h PenaltyCard.h)

# Add executable
add_executable(Memory_MatchCard_Game ${SRCS})

# Link wxWidgets libraries
