#include "baumhausengine.h"

#include <string>
#include <iostream>

/*

Baumhaus Engine 2017

By publishing this engine, you agree to publish the code with it.

This code comes with no warranty at all; not even the warranty to work properly and comercially

*/

CBaumhausengine::CBaumhausengine(bool debugMode)
{
    this->position = new CPos;
    this->pipe = new CPipe(debugMode);
	this->debugMode = debugMode;
    //ctor
}

CBaumhausengine::~CBaumhausengine()
{
	delete this->position;
	delete this->pipe;
    //dtor
}

void CBaumhausengine::init() {
	this->random = false; // by default random is off
	this->colorOnTurn = true; // white starts the match
	this->color = false; // engine will play black
	pipe->d("End - init()");
}

void CBaumhausengine::analyzePos() {
	// TODO Main thinking logic would probably be here.

	// . . .

	// we should have candidate move now.
	std::string tempMove = "e7e5";
	makeMove(tempMove);
	pipe->queueOutputMessage("move " + tempMove);
}

void CBaumhausengine::ponderPos() {

}

void CBaumhausengine::updateSquares() {

}

void CBaumhausengine::setColor(bool colorI) { //the playing-color
    color = colorI;
}

bool CBaumhausengine::getColor() {
    return color;
}

void CBaumhausengine::startRoutine() {

	pipe->d("Baumhaus Engine started up... Waiting for Signals");

	std::string message;
	while (true) { //just simply spools to wait for a signal
		message = pipe->dequeueInputMessage(false);
		
		if("quit" == message) {
			break;
		} 
		else if ("new" == message) {
			init();
		}
		else if("ping" == message) {
			pong(pipe->dequeueInputMessage(true));
		}
		else if("random" == message) {
			this->random = !this->random;
		}
		else if ("usermove" == message) {
			std::string move = pipe->dequeueInputMessage(true);
			// validate move
			// TODO
			
			// if validation checks out. make the move.
			makeMove(move);
		}

		// we've handled the message (assimung there was one), we can continue pondering/thinking
		if(this->color == this->colorOnTurn) { // engine's turn
			analyzePos();
		}
		else {
			ponderPos();
		}
	}

	pipe->d("Goodbye!");
}

void CBaumhausengine::pong(std::string val) {
	this->pipe->queueOutputMessage("pong " + val);
}

void CBaumhausengine::makeMove(std::string move) {
	// update position to reflect move

	// other color's turn
	this->colorOnTurn = !this->colorOnTurn;
	pipe->d("color on turn: " + std::to_string(colorOnTurn));
}