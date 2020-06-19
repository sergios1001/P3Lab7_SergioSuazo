#include "Post.h"

Post::Post(string _titulo,string _contenido)
{
	titulo = _titulo;
	contenido = _contenido;
	likes = 0;
	hates = 0;
}

Post::~Post()
{
}

string Post::getTitulo(){
	return titulo;
}
string Post::getContenido(){
	return contenido;
}

int Post::getLikes(){
	return likes;
}
void Post::setLikes(int _like){
	likes = _like;
}

int Post::getHates(){
	return hates;
}

void Post::setHates(int hate){
	hates = hate;
}

vector<Comentario*> Post::getComments(){
	return misComments;
}
void Post::addComment(Comentario* comment){
	misComments.push_back(comment);
}
