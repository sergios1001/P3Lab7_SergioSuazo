#ifndef POST_H
#define POST_H
#include <vector>
#include "Comentario.h"

using namespace std;

class Post
{
	public:
		Post(string,string);
		
		string getTitulo();
		string getContenido();
		
		int getLikes();
		void setLikes(int);
		int getHates();
		void setHates(int);
		
		vector<Comentario*> getComments();
		void addComment(Comentario*);
		
		~Post();
	protected:
		string titulo, contenido;
		int likes, hates;
		vector<Comentario*> misComments;
};

#endif
