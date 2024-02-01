
// camada de aplicação (superior) ---------------
// aplication
int main1(void) {
	
	// 1) usuários/atores???
	// 2) Como cada usuário pretende utilizar esta classe? (Quais são os casos de uso?)
	// listar todos os elementos no container
	// 
}

// aplication
int main2(void) {
		
	// 1) usuários/atores???
	// 2) Como cada usuário pretende utilizar esta classe? (Quais são os casos de uso?)
	// 3) Quais funcionalidades cada usuário deseja? Qual comportamento do software esperado por cada usuário?
	// 4) Quais são os critérios de aceitação para cada funcionalidade requerida?
	// 5) Quais são os cenários de teste que materializam estes critérios de aceitação?
	// listar todos os elementos no container
	
	// ------------------
	// cliente
	send_resquet();
	receive_file()
	
	// servidor 
	receive_request();
	send_file();
}

// aplication
int main3(void) {
	
	
	// 1) usuários/atores???
	// 2) Como cada usuário pretende utilizar esta classe? (Quais são os casos de uso?)
	// listar todos os elementos no container
	
	
	// ---------------- precisa ter a certeza que 
	// ---------------- servidor está online antes
	// ---------------- de enviar um request
	// cliente
	Connection c = openConnection(); // sincrono
	c.send_resquet();
	c.receive_file();
	c.close();
	
	// servidor 
	while( true ) {
		Connection c;
		c.wait() // sincrono
		receive_request();
		send_file();
		c.close();
	}
}

// ----------- camada inferior
// biblioteca ou framework 
template <class T>
class Container {
	?????
   // add(?)
   // remove(?)
   // update(?)
   // get(?)
   
   intertor it;
   begin()
   end()
   
  
};