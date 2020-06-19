#include "Usuario.h"

Usuario::Usuario(string _nombre,string _usuario,string _contra )
{
	nombre=_nombre;
	usuario = _usuario;
	contra = _contra;
}

string Usuario::getNombre(){
	return nombre;
}
void Usuario::setNombre(string _nombre)
{
	nombre= _nombre;
}
string Usuario::getUser(){
	return usuario;
}
void Usuario::setUser(string _usuario)
{
	usuario = _usuario;
}
string Usuario::getContra(){
	return contra;
}
void Usuario::setContra(string _contra)
{
	contra = _contra;
}

vector<Post*> Usuario::getPost(){
	return misPosts;
}
void Usuario::setPost(Post* post){
	misPosts.push_back(post);
}

vector<Usuario*> Usuario::getFollows(){
	return misFollows;
}

void Usuario::setFollows(Usuario* user){
	misFollows.push_back(user);
}


Usuario::~Usuario()
{
}
