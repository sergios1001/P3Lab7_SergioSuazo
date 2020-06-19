#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <vector>
#include "Post.h"

using namespace std;


class Usuario
{
	public:
		Usuario(string,string,string);
		
		string getNombre();
		void setNombre(string);
		string getUser();
		void setUser(string);
		string getContra();
		void setContra(string);
		
		vector<Post*> getPost();
		void setPost(Post*);
		
		vector<Usuario*> getFollows();
		void setFollows(Usuario*);
		
		
		~Usuario();
	protected:
		
		string nombre, usuario, contra;
		vector<Post*> misPosts;
		vector<Usuario*> misFollows;
		
		
		
};

#endif
