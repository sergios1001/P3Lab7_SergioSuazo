#include "Comentario.h"

Comentario::Comentario(string _nombre,string _comment)
{
	nombre = _nombre;
	comment = _comment;
}

Comentario::~Comentario()
{
}

string Comentario::getNombre(){
	return nombre;
}
string Comentario::getComment(){
	return comment;
}
