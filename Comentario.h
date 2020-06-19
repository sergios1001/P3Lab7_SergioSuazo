#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <string>

using namespace std;

class Comentario
{
	public:
		Comentario(string, string);
		
		string getNombre();
		string getComment();
		
		~Comentario();
	protected:
		string nombre,comment;
};

#endif
