#include <iostream>
#include <string>
#include <vector>
#include "Usuario.h"
#include "Post.h"
#include "Comentario.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int menu(){
	int retValue=0;
	
	while(retValue < 1 || retValue > 7){
		
			<<"1.- Crear Post"<<endl
			<<"2.- Comentar post"<<endl
			<<"3.- Dar Like"<<endl
			<<"4.- Dar Hate"<<endl
			<<"5.- Seguir Usuario"<<endl
			<<"6.- Dejar de seguir Usuario"<<endl
			<<"7.- Logout"<<endl
			<<"Ingrese una opcion entre 1 y 7: ";
			
			cin>>retValue;

			
			if(retValue >= 1 && retValue <= 7){
				break;
			}
				
			else{
						
				cout<<endl<<"Opcion incorrecta, elija nuevamente "<<endl;
			}
					
	}//end while
	
	
	return retValue;
}

int menu2(){
	int retValue=0;
	
	while(retValue < 1 || retValue > 2){
		
		cout<<"       Caralibro"<<endl
			<<"1.- Ingresar"<<endl
			<<"2.- Crear Cuenta"<<endl
			<<"2.- Salir"<<endl
			<<"Ingrese una opcion entre 1 y 2: ";
			
			cin>>retValue;

			
			if(retValue >= 1 && retValue <= 2){
				break;
			}
				
			else{
						
				cout<<endl<<"Opcion incorrecta, elija nuevamente "<<endl;
			}
					
	}//end while
	
	
	return retValue;
}

Usuario* miUsuario;
vector<Usuario*> listaUser;
vector<Post*> miFeed;


int main(int argc, char** argv) {
	
	int option1=0
	while(opcion!=3)
	{
		switch(option = menu2() ){
			case 1:{
				string user, contra;
				bool login=false
				while(!login)
				{
					cout<<"Ingrese su Usuario: ";
					cin>>user;
					cout<<"Ingrese su Contraseña: ";
					cin>>contra;
					
					for(i=0;i<listaUser.size();i++){
						if(user==listaUser[i]->getUser() && contra==listaUser[i]->getContra())
						{
							login=true;
							miUsuario = listaUser[i];
							break;
						}
					}
					
					if(!login){
						cout<<"Usuario o Contraseña incorrecta, ingrese nuevamente"<< endl;
					}
				}
					
				int option=0;
				while( option != 7 ) {
					miFeed.clear();
					for(int i=0;i<miUsuario->getFollows().size();i++){
						for(int j=0;j<miUsuario->getFollows()[i]->getPost().size();j++)
						{
							miFeed.push_back(miUsuario->getFollows()[i]->getPost()[j]);
						}
					}
					for(int i=0;i<miUsuario->getPost().size();i++){
						miFeed.push_back(miUsuario->getPost()[i]);
					}
					int post=0;
					//impresion del feed
					for(int i=0;i<miUsuario->getFollows().size();i++){
						cout<<": por"<<miUsuario->getFollows()[i]<<" :"<<endl
						for(int j=0;j<miUsuario->getFollows()[i]->getPost().size();j++)
						{
							cout<<"#"<<post<<"----------------------------"<<endl;
							cout<<"::"<<miUsuario->getFollows()[i]->getPost()[j]->getTitulo()<<"::"<<endl;
							cout<<"["<<miUsuario->getFollows()[i]->getPost()[j]->getContenido()<<"]"<<endl;
							cout<<"{likes: "<<miUsuario->getFollows()[i]->getPost()[j]->getLikes()<<"}"<<" {hates: "<<miUsuario->getFollows()[i]->getPost()[j]->getHates()<<"}"<<endl;
							cout<<":COMENTARIOS:"<<endl;
							for(int k=0;k<miUsuario->getFollows()[i]->getPost()[j]->getComments().size();k++)
							{
								cout<<"_________________________________________"<<endl;
								cout<<"   de "<<miUsuario->getFollows()[i]->getPost()[j]->getComments()[k]->getNombre()<<endl;
								cout<<"     ["<<miUsuario->getFollows()[i]->getPost()[j]->getComments()->getComment()<<"]"<<endl;
								cout<<"_________________________________________"<<endl;
							}
							post++;
						}
					}
					cout<<":Mis Posts:"<<endl;
					for(int i=0;i<miUsuario->getPost().size();i++){
						cout<<"#"<<post<<"----------------------------"<<endl;
						cout<<"::"<<miUsuario->getPost()[i]->getTitulo()<<"::"<<endl;
						cout<<"["<<miUsuario->>getPost()[i]->getContenido()<<"]"<<endl;
						cout<<"{likes: "<<miUsuario->getPost()[i]->getLikes()<<"}"<<" {hates: "<<miUsuario->getPost()[i]->getHates()<<"}"<<endl;
						cout<<":COMENTARIOS:"<<endl;
						for(int k=0;k<miUsuario->getPost()[i]->getComments().size();k++)
						{
							cout<<"_________________________________________"<<endl;
							cout<<"   de "<<miUsuario->getPost()[i]->getComments()[k]->getNombre()<<endl;
							cout<<"     ["<<miUsuario->getPost()[i]->getComments()->getComment()<<"]"<<endl;
							cout<<"_________________________________________"<<endl;
						}
						post++;
					}
					
					
					switch( option = menu() ){ 
					
						case 1:{
							string titulo, contenido;
							cout<<"Ingrese el titulo del post: ";
							getLine(cin,titulo);
							cout<<"Ingrese el contenido: ";
							getLine(cin,contenido);
							miUsuario->setPost(new Post(titulo,contenido));
							cout<< "Se creo el post exitosamente"<<endl;
							break;
						}
						case 2:{
							int indice;
							string comentario;
							cout<<"Indique el post en el que desea comentar: ";
							cin>>indice;
							cout<<"Escriba el comentario: ";
							getLine(cin,comentario);
							miFeed[indice]->addComment(comentario);
							cout<<"Comentario posteado exitosamente!"<<endl;
						} 
						    
						case 3:{
							int indice;
							cout<<"Indique el post al que desea darle like: ";
							cin>>indice;
							
							miFeed[indice]->setLikes(miFeed[indice]->getLikes()+1);
							cout<<"Se dio like al post"<<endl;
							break;
						}
						
						case 4:{
							int indice;
							cout<<"Indique el post al que desea darle hate: ";
							cin>>indice;
							
							miFeed[indice]->setHates(miFeed[indice]->getHates()+1);
							cout<<"Se dio hate al post"<<endl;
							break;
						}
						
						case 5:{
							for(int i = 0; i<listaUser.size();i++)
							{
								bool siguiendo=false;
								for(int j = 0; j< miUsuario->getFollows().size();j++)
								{
									if(miUsuario->getFollows()[j]==listaUser[i])
									{
										siguiendo=true;
										break;
									}
								}
								if(!siguiendo)
								{
									cout<<i<<"- "<<listaUser[i]->getNombre()<<endl;
								}	
							}
							int seleccion;
							cout<<"Seleccione al usuario al que desea seguir: ";
							cin>>seleccion;
							miUsuario->setFollows(listaUser[seleccion]);
							break;
						}
						
						case 6:{
							for(int i=0;i<miUsuario->getFollows().size();i++)
							{
								cout<<i<<"- "<<miUsuario->getFollows()[i]->getNombre()<<endl;
							}
							int seleccion;
							cout<<"Seleccione al Usuario al que desea dejar de seguir: ";
							cin>>seleccion;
							
							miUsuario->getFollows().erase(miUsuario->getFollows().begin()+seleccion);
							cout<<:"Se dejo de seguir al usuario seleccionado"<<endl;
							break;
						}
						
						case 7:{
			
							//salir
							cout<<"Logout..."<<endl;
							break;
						}
									
					}//switch
				
				}//while
				break;
			}
			case 2:{
				string nombre, user, contra;
				cout<<"Ingrese su nombre: ";
				cin>>nombre;
				cout<<"Ingrese su usuario: ";
				cin>>user;
				cout<<"Ingrese su contraseña: ";
				cin>>contra;
				
				listaUser.push_back(new Usuario(nombre,user,contra));
				cout<<"Se creo el usuario exitosamente!"<<endl;				
				
				break;
			}
			case 3:{
				//salir
				cout<<"Saliendo del programa..."<<endl;
				break;
			}
		}
	}
	
	return 0;
}










































