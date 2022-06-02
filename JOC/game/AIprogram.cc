#include "Player.hh"

/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME program // sub6


struct PLAYER_NAME : public Player {
	/**
	* Factory: returns a new instance of this class.
	* Do not modify this function.
	*/
	static Player* factory () {
		return new PLAYER_NAME;
	}
	/**
	* Types and attributes for your player can be defined here.
	*/
	// bfs para buscar a enemigos workers + soldiers -> nat2
	bool bfs_a_enemigos2 (Pos p, Dir& dir, int& dist, vector<vector<bool>>& no_os_mateis_gracias) {
		vector<vector<bool>> visitado (board_rows(), vector<bool>(board_cols(),false));
	    queue<pair<pair<Pos,int>,Dir>> q; 

	    int x, y;
		x = p.i; 
		y = p.j;  

		if (!visitado[x][y]) { 
			visitado[x][y] = true; 
			if (pos_ok(p+Up) and cell(p+Up).type != Water and sies(p+Up) and not no_os_mateis_gracias[(p+Up).i][p.j]) q.push(make_pair(make_pair(p+Up,1),Up));		
			if (pos_ok(p+Down) and cell(p+Down).type != Water and sies(p+Down) and not no_os_mateis_gracias[(p+Down).i][p.j]) q.push(make_pair(make_pair(p+Down,1),Down));
			if (pos_ok(p+Left) and cell(p+Left).type != Water and sies(p+Left) and not no_os_mateis_gracias[p.i][(p+Left).j]) q.push(make_pair(make_pair(p+Left,1),Left));
			if (pos_ok(p+Right) and cell(p+Right).type != Water and sies(p+Right) and not no_os_mateis_gracias[p.i][(p+Right).j]) q.push(make_pair(make_pair(p+Right,1),Right));
		}
		while (!q.empty()) {
			p = q.front().first.first;
			x = p.i; 
			y = p.j;  
			dist = q.front().first.second;
			dir = q.front().second;
			q.pop();

			if (ant(cell(p).id).type != Queen) return true;
			else if (!visitado[x][y]) { 
				visitado[x][y] = true; 
				if (pos_ok(p+Up) and cell(p+Up).type != Water and sies(p+Up) and not no_os_mateis_gracias[(p+Up).i][p.j]) q.push(make_pair(make_pair(p+Up,dist+1),dir));		
				if (pos_ok(p+Down) and cell(p+Down).type != Water and sies(p+Down) and not no_os_mateis_gracias[(p+Down).i][p.j]) q.push(make_pair(make_pair(p+Down,dist+1),dir));
				if (pos_ok(p+Left) and cell(p+Left).type != Water and sies(p+Left) and not no_os_mateis_gracias[p.i][(p+Left).j]) q.push(make_pair(make_pair(p+Left,dist+1),dir));
				if (pos_ok(p+Right) and cell(p+Right).type != Water and sies(p+Right) and not no_os_mateis_gracias[p.i][(p+Right).j]) q.push(make_pair(make_pair(p+Right,dist+1),dir));
			}
		}
		return false;
	}
	// bfs camino ida para buscar bonus de parte de la reina
	bool bfs_a_bonus_reina (Pos p, Dir& dir, int& dist, vector<vector<bool>>& no_os_mateis_gracias) {
		vector<vector<bool>> visitado (board_rows(), vector<bool>(board_cols(),false));
	    queue<pair<pair<Pos,int>,Dir>> q; 

	    int x, y;
		x = p.i; 
		y = p.j;  

		if (!visitado[x][y]) { 
			visitado[x][y] = true; 
			if (pos_ok(p+Up) and cell(p+Up).type != Water and cell(p+Up).id == -1 and not no_os_mateis_gracias[(p+Up).i][p.j]) q.push(make_pair(make_pair(p+Up,1),Up));		
			if (pos_ok(p+Down) and cell(p+Down).type != Water and cell(p+Down).id == -1 and not no_os_mateis_gracias[(p+Down).i][p.j]) q.push(make_pair(make_pair(p+Down,1),Down));
			if (pos_ok(p+Left) and cell(p+Left).type != Water and cell(p+Left).id == -1 and not no_os_mateis_gracias[p.i][(p+Left).j]) q.push(make_pair(make_pair(p+Left,1),Left));				
			if (pos_ok(p+Right) and cell(p+Right).type != Water and cell(p+Right).id == -1 and not no_os_mateis_gracias[p.i][(p+Right).j]) q.push(make_pair(make_pair(p+Right,1),Right));
		}
		while (!q.empty()) {
			p = q.front().first.first;
			x = p.i; 
			y = p.j;  
			dist = q.front().first.second;
			dir = q.front().second;
			q.pop();

			if (cell(p).bonus != None) return true;
			else if (!visitado[x][y]) { 
				visitado[x][y] = true; 
				if (pos_ok(p+Up) and cell(p+Up).type != Water and cell(p+Up).id == -1 and not no_os_mateis_gracias[(p+Up).i][p.j]) q.push(make_pair(make_pair(p+Up,dist+1),dir));		
			if (pos_ok(p+Down) and cell(p+Down).type != Water and cell(p+Down).id == -1 and not no_os_mateis_gracias[(p+Down).i][p.j]) q.push(make_pair(make_pair(p+Down,dist+1),dir));
			if (pos_ok(p+Left) and cell(p+Left).type != Water and cell(p+Left).id == -1 and not no_os_mateis_gracias[p.i][(p+Left).j]) q.push(make_pair(make_pair(p+Left,dist+1),dir));				
			if (pos_ok(p+Right) and cell(p+Right).type != Water and cell(p+Right).id == -1 and not no_os_mateis_gracias[p.i][(p+Right).j]) q.push(make_pair(make_pair(p+Right,dist+1),dir));
		}
		}
		return false;
	}
	// bfs camino de vuelta para encontrar a la reina	 nat2 jutge
	bool bfs_a_historia (Pos p, int my_queen_id, Dir& dir, int& dist, vector<vector<bool>>& no_os_mateis_gracias) {
		vector<vector<bool>> visitado (board_rows(), vector<bool>(board_cols(),false));
	    queue<pair<pair<Pos,int>,Dir>> q; 

	    int x, y;
		x = p.i; 
		y = p.j;
		
		if (!visitado[x][y]) { 
			visitado[x][y] = true; 
			if (pos_ok(p+Up) and cell(p+Up).type != Water and (cell(p+Up).id == -1 or cell(p+Up).id == my_queen_id) and not no_os_mateis_gracias[(p+Up).i][p.j]) q.push(make_pair(make_pair(p+Up,1),Up));		
			if (pos_ok(p+Down) and cell(p+Down).type != Water and (cell(p+Down).id == -1 or cell(p+Down).id == my_queen_id) and not no_os_mateis_gracias[(p+Down).i][p.j]) q.push(make_pair(make_pair(p+Down,1),Down));
			if (pos_ok(p+Left) and cell(p+Left).type != Water and (cell(p+Left).id == -1 or cell(p+Left).id == my_queen_id) and not no_os_mateis_gracias[p.i][(p+Left).j]) q.push(make_pair(make_pair(p+Left,1),Left));
			if (pos_ok(p+Right) and cell(p+Right).type != Water and (cell(p+Right).id == -1 or cell(p+Right).id == my_queen_id) and not no_os_mateis_gracias[p.i][(p+Right).j]) q.push(make_pair(make_pair(p+Right,1),Right));
		}
		while (!q.empty()) {
			p = q.front().first.first;
			x = p.i; 
			y = p.j;  
			dist = q.front().first.second;
			dir = q.front().second;
			q.pop();

			if (cell(p).id == my_queen_id) return true;
			else if (!visitado[x][y]) { 
				visitado[x][y] = true; 
				if (pos_ok(p+Up) and cell(p+Up).type != Water and (cell(p+Up).id == -1 or cell(p+Up).id == my_queen_id) and not no_os_mateis_gracias[(p+Up).i][p.j]) q.push(make_pair(make_pair(p+Up,dist+1),dir));		
				if (pos_ok(p+Down) and cell(p+Down).type != Water and (cell(p+Down).id == -1 or cell(p+Down).id == my_queen_id) and not no_os_mateis_gracias[(p+Down).i][p.j]) q.push(make_pair(make_pair(p+Down,dist+1),dir));
				if (pos_ok(p+Left) and cell(p+Left).type != Water and (cell(p+Left).id == -1 or cell(p+Left).id == my_queen_id) and not no_os_mateis_gracias[p.i][(p+Left).j]) q.push(make_pair(make_pair(p+Left,dist+1),dir));
				if (pos_ok(p+Right) and cell(p+Right).type != Water and (cell(p+Right).id == -1 or cell(p+Right).id == my_queen_id) and not no_os_mateis_gracias[p.i][(p+Right).j]) q.push(make_pair(make_pair(p+Right,dist+1),dir));
			}
		}
		return false;
	}
	// bfs camino ida para buscar bonus
	bool bfs_a_bonus (Pos p, Dir& dir, int& dist, vector<vector<bool>>& dejar_comida, vector<vector<bool>>& no_os_mateis_gracias) {
		vector<vector<bool>> visitado (board_rows(), vector<bool>(board_cols(),false));
	    queue<pair<pair<Pos,int>,Dir>> q; 

	    int x, y;
		x = p.i; 
		y = p.j;  

		if (!visitado[x][y]) { 
			visitado[x][y] = true; 
			if (pos_ok(p+Up) and cell(p+Up).type != Water and cell(p+Up).id == -1 and not dejar_comida[(p+Up).i][p.j] and not no_os_mateis_gracias[(p+Up).i][p.j]) q.push(make_pair(make_pair(p+Up,1),Up));		
			if (pos_ok(p+Down) and cell(p+Down).type != Water and cell(p+Down).id == -1 and not dejar_comida[(p+Down).i][p.j] and not no_os_mateis_gracias[(p+Down).i][p.j]) q.push(make_pair(make_pair(p+Down,1),Down));
			if (pos_ok(p+Left) and cell(p+Left).type != Water and cell(p+Left).id == -1 and not dejar_comida[p.i][(p+Left).j] and not no_os_mateis_gracias[p.i][(p+Left).j]) q.push(make_pair(make_pair(p+Left,1),Left));
			if (pos_ok(p+Right) and cell(p+Right).type != Water and cell(p+Right).id == -1 and not dejar_comida[p.i][(p+Right).j] and not no_os_mateis_gracias[p.i][(p+Right).j]) q.push(make_pair(make_pair(p+Right,1),Right));
		}
		while (!q.empty()) {
			p = q.front().first.first;
			x = p.i; 
			y = p.j;  
			dist = q.front().first.second;
			dir = q.front().second;
			q.pop();

			if (cell(p).bonus != None and dejar_comida[p.i][p.j]== false) return true;
			else if (!visitado[x][y]) { 
				visitado[x][y] = true; 
				if (pos_ok(p+Up) and cell(p+Up).type != Water and cell(p+Up).id == -1 and not dejar_comida[(p+Up).i][p.j] and not no_os_mateis_gracias[(p+Up).i][p.j]) q.push(make_pair(make_pair(p+Up,dist+1),dir));		
				if (pos_ok(p+Down) and cell(p+Down).type != Water and cell(p+Down).id == -1 and not dejar_comida[(p+Down).i][p.j] and not no_os_mateis_gracias[(p+Down).i][p.j]) q.push(make_pair(make_pair(p+Down,dist+1),dir));
				if (pos_ok(p+Left) and cell(p+Left).type != Water and cell(p+Left).id == -1 and not dejar_comida[p.i][(p+Left).j] and not no_os_mateis_gracias[p.i][(p+Left).j]) q.push(make_pair(make_pair(p+Left,dist+1),dir));
				if (pos_ok(p+Right) and cell(p+Right).type != Water and cell(p+Right).id == -1 and not dejar_comida[p.i][(p+Right).j] and not no_os_mateis_gracias[p.i][(p+Right).j]) q.push(make_pair(make_pair(p+Right,dist+1),dir));
			}
		}
		return false;
	}
	// si es enemigo o no es
	bool sies (Pos p) {
		if (cell(p).id == -1) return false;
		Ant a3 = ant(cell(p).id);
		if (a3.player != me()) return true;
		return false;
	}
	bool siesworker (Pos p) {
		if (cell(p).id == -1) return false;
		Ant a3 = ant(cell(p).id);
		if (a3.player != me() and ant(cell(p).id).type == Worker) return true;
		return false;
	}
	// si es mi hormiga
	bool mia_bonus (Pos p) {
		if (cell(p).id != -1) {
			Ant a3 = ant(cell(p).id);
			if (a3.player == me() and a3.bonus != None) return true;
		}
		return false;
	}
	// bfs a hormigas con comida
	bool bfs_a_hormigas_con_bonus(Pos p, Dir& dir, int& dist, vector<vector<bool>>& no_os_mateis_gracias) {
		vector<vector<bool>> visitado (board_rows(), vector<bool>(board_cols(),false));
	    queue<pair<pair<Pos,int>,Dir>> q; 

	    int x, y;
		x = p.i; 
		y = p.j;  

		if (!visitado[x][y]) { 
			visitado[x][y] = true; 
			if (pos_ok(p+Up) and cell(p+Up).type != Water and mia_bonus(p+Up) and not no_os_mateis_gracias[(p+Up).i][p.j]) q.push(make_pair(make_pair(p+Up,1),Up));		
			if (pos_ok(p+Down) and cell(p+Down).type != Water and mia_bonus(p+Down) and not no_os_mateis_gracias[(p+Down).i][p.j]) q.push(make_pair(make_pair(p+Down,1),Down));
			if (pos_ok(p+Left) and cell(p+Left).type != Water and mia_bonus(p+Left) and not no_os_mateis_gracias[p.i][(p+Left).j]) q.push(make_pair(make_pair(p+Left,1),Left));
			if (pos_ok(p+Right) and cell(p+Right).type != Water and mia_bonus(p+Right) and not no_os_mateis_gracias[p.i][(p+Right).j]) q.push(make_pair(make_pair(p+Right,1),Right));
		}
		while (!q.empty()) {
			p = q.front().first.first;
			x = p.i; 
			y = p.j;  
			dist = q.front().first.second;
			dir = q.front().second;
			q.pop();

			if (mia_bonus(p)) return true;
			else if (!visitado[x][y]) { 
				visitado[x][y] = true; 
				if (pos_ok(p+Up) and cell(p+Up).type != Water and not no_os_mateis_gracias[(p+Up).i][p.j]) q.push(make_pair(make_pair(p+Up,dist+1),dir));		
				if (pos_ok(p+Down) and cell(p+Down).type != Water and not no_os_mateis_gracias[(p+Down).i][p.j]) q.push(make_pair(make_pair(p+Down, dist+1),dir));
				if (pos_ok(p+Left) and cell(p+Left).type != Water and not no_os_mateis_gracias[p.i][(p+Left).j]) q.push(make_pair(make_pair(p+Left, dist+1),dir));
				if (pos_ok(p+Right) and cell(p+Right).type != Water and not no_os_mateis_gracias[p.i][(p+Right).j]) q.push(make_pair(make_pair(p+Right, dist+1),dir));
			}
		}
		return false;
	}
	// bfs a enemigos desde soldados
	bool bfs_a_enemigos (Pos p, Dir& dir, int& dist, vector<vector<bool>>& no_os_mateis_gracias) {
		vector<vector<bool>> visitado (board_rows(), vector<bool>(board_cols(),false));
	    queue<pair<pair<Pos,int>,Dir>> q; 

	    int x, y;
		x = p.i; 
		y = p.j;  
		
		if (!visitado[x][y]) { 
			visitado[x][y] = true; 
			if (pos_ok(p+Up) and cell(p+Up).type != Water and (siesworker(p+Up) or cell(p+Up).id == -1) and not no_os_mateis_gracias[(p+Up).i][p.j]) q.push(make_pair(make_pair(p+Up,1),Up));		
			if (pos_ok(p+Down) and cell(p+Down).type != Water and (siesworker(p+Down) or cell(p+Down).id == -1) and not no_os_mateis_gracias[(p+Down).i][p.j]) q.push(make_pair(make_pair(p+Down,1),Down));
			if (pos_ok(p+Left) and cell(p+Left).type != Water and (siesworker(p+Left) or cell(p+Left).id == -1) and not no_os_mateis_gracias[p.i][(p+Left).j]) q.push(make_pair(make_pair(p+Left,1),Left));
			if (pos_ok(p+Right) and cell(p+Right).type != Water and (siesworker(p+Right) or cell(p+Right).id == -1) and not no_os_mateis_gracias[p.i][(p+Right).j]) q.push(make_pair(make_pair(p+Right,1),Right));
		}
		while (!q.empty()) {
			p = q.front().first.first;
			x = p.i; 
			y = p.j;  
			dist = q.front().first.second;
			dir = q.front().second;
			q.pop();

			if (siesworker(p)) return true;
			else if (!visitado[x][y]) { 
				visitado[x][y] = true; 
				if (pos_ok(p+Up) and cell(p+Up).type != Water and (siesworker(p+Up) or cell(p+Up).id == -1) and not no_os_mateis_gracias[(p+Up).i][p.j]) q.push(make_pair(make_pair(p+Up,dist+1),dir));		
				if (pos_ok(p+Down) and cell(p+Down).type != Water and (siesworker(p+Down) or cell(p+Down).id == -1) and not no_os_mateis_gracias[(p+Down).i][p.j]) q.push(make_pair(make_pair(p+Down,dist+1),dir));
				if (pos_ok(p+Left) and cell(p+Left).type != Water and (siesworker(p+Left) or cell(p+Left).id == -1) and not no_os_mateis_gracias[p.i][(p+Left).j]) q.push(make_pair(make_pair(p+Left,dist+1),dir));
				if (pos_ok(p+Right) and cell(p+Right).type != Water and (siesworker(p+Right) or cell(p+Right).id == -1) and not no_os_mateis_gracias[p.i][(p+Right).j]) q.push(make_pair(make_pair(p+Right,dist+1),dir));
			}
		}
		return false;
	}
	// comprobando la matriz de hormigas -> moverse + actualizar matriz
	void hay_que_moverse (Pos p, Dir dir, int quien_id, vector<vector<bool>>& no_os_mateis_gracias) {
		if (dir == Up or dir == Down) {
			if (no_os_mateis_gracias[(p+dir).i][p.j] == false) {		
				move (quien_id, dir);
				no_os_mateis_gracias[(p+dir).i][p.j] = true;
				no_os_mateis_gracias[p.i][p.j] = false;
			}
		}
		else if (dir == Left or dir == Right) {
			if (no_os_mateis_gracias[p.i][(p+dir).j] == false) {		
				move (quien_id, dir);
				no_os_mateis_gracias[p.i][(p+dir).j] = true;
				no_os_mateis_gracias[p.i][p.j] = false;
			}
		}
	}
	void dnd_voy_al_final(Pos p3, int my_queen_id, Dir dir, int dist, Dir dir2, int dist2, vector<vector<bool>>& no_os_mateis_gracias) {
		if ((dist2 == 1 and cell(p3+dir2).id == -1) or (dist2 == 1 and sies(p3+dir2))) hay_que_moverse(p3, dir2, my_queen_id, no_os_mateis_gracias);
        else if (dist <= dist2 and cell(p3+dir).id == -1) hay_que_moverse(p3, dir, my_queen_id, no_os_mateis_gracias);
    }
	// donde dejar el huevo de la reina
	pair<bool,Dir> donde_lay (Pos p) {
		if (cell(p+Up).type != Water and pos_ok(p+Up) and cell(p+Up).id == -1) return make_pair(true, Up);		
		if (cell(p+Down).type != Water and pos_ok(p+Down) and cell(p+Down).id == -1) return make_pair(true, Down);
		if (cell(p+Left).type != Water and pos_ok(p+Left) and cell(p+Left).id == -1) return make_pair(true, Left);
		if (cell(p+Right).type != Water and pos_ok(p+Right) and cell(p+Right).id == -1) return make_pair(true, Right);
		return make_pair(false, Up);
	}
	//qué huevo sale 
	void lay_eggs (Ant a3, int wksize, int sdsize) {
		int i = random(0,1);
		if (wksize < 1 or i == 0) {
			if (a3.reserve[0] >= 1 and a3.reserve[1] >= 1 and a3.reserve[2] >= 1) {
				if (donde_lay(a3.pos).first) lay(a3.id, donde_lay(a3.pos).second, Worker); 
			}
		}
		else if (sdsize < 4 or i == 1) {
			if (a3.reserve[0] >= 3 and a3.reserve[1] >= 3 and a3.reserve[2] >= 3) {
				if (donde_lay(a3.pos).first) lay(a3.id, donde_lay(a3.pos).second, Soldier); 
			}
		}
	}
	// veo a la reina en dist < 3
	bool hay_a_3 (Pos p, int my_queen_id, Dir& dir, int& dist) {
		vector<vector<bool>> visitado (board_rows(), vector<bool>(board_cols(),false));
	    queue<pair<pair<Pos,int>,Dir>> q; 

	    int x, y;
		x = p.i; 
		y = p.j;
		int i = 0;
		
		if (!visitado[x][y]) { 
			visitado[x][y] = true; 
			if (pos_ok(p+Up) and cell(p+Up).type != Water and cell(p+Up).id == my_queen_id) {
				dir = Up;
				dist = 1;
				return true;
			}
			else if(pos_ok(p+Up) and cell(p+Up).type != Water and cell(p+Up).id == -1) q.push(make_pair(make_pair(p+Up,1),Up));
			if (pos_ok(p+Down) and cell(p+Down).type != Water and cell(p+Down).id == my_queen_id) {
				dir = Down;
				dist = 1;
				return true;
			}
			else if(pos_ok(p+Down) and cell(p+Down).type != Water and cell(p+Down).id == -1) q.push(make_pair(make_pair(p+Down,1),Down));
			if (pos_ok(p+Left) and cell(p+Left).type != Water and cell(p+Left).id == my_queen_id) {
				dir = Left;
				dist = 1;
				return true;
			}
			else if(pos_ok(p+Left) and cell(p+Left).type != Water and cell(p+Left).id == -1) q.push(make_pair(make_pair(p+Left,1),Left));
			if (pos_ok(p+Right) and cell(p+Right).type != Water and cell(p+Right).id == my_queen_id) {
				dir = Right;
				dist = 1;
				return true;
			}
			else if(pos_ok(p+Right) and cell(p+Right).type != Water and cell(p+Right).id == -1) q.push(make_pair(make_pair(p+Right,1),Right));
			
		}
		while (!q.empty() and i < 3) {
			p = q.front().first.first;
			x = p.i; 
			y = p.j;  
			dist = q.front().first.second;
			dir = q.front().second;
			q.pop();

			if (cell(p).id == my_queen_id) return true;
			else if (!visitado[x][y]) { 
				visitado[x][y] = true; 
				if (pos_ok(p+Up) and cell(p+Up).type != Water and cell(p+Up).id == my_queen_id) q.push(make_pair(make_pair(p+Up,dist+1),dir));		
				if (pos_ok(p+Down) and cell(p+Down).type != Water and cell(p+Down).id == my_queen_id) q.push(make_pair(make_pair(p+Down,dist+1),dir));
				if (pos_ok(p+Left) and cell(p+Left).type != Water and cell(p+Left).id == my_queen_id) q.push(make_pair(make_pair(p+Left,dist+1),dir));
				if (pos_ok(p+Right) and cell(p+Right).type != Water and cell(p+Right).id == my_queen_id) q.push(make_pair(make_pair(p+Right,dist+1),dir));
			}
			++i;
		}
		return false;
	}
	//bloquear casillas adyacentes de la reina si tienen comida
	void bloquear(Pos p, vector<vector<bool>>& dejar_comida) {
		if (pos_ok(p+Up) and cell(p+Up).type != Water and cell(p+Up).bonus != None and cell(p+Up).id == -1) dejar_comida[(p+Up).i][p.j] = true;
		else if (pos_ok(p+Down) and cell(p+Down).type != Water and cell(p+Down).bonus != None and cell(p+Down).id == -1) dejar_comida[(p+Down).i][p.j] = true;
		else if (pos_ok(p+Left) and cell(p+Left).type != Water and cell(p+Left).bonus != None and cell(p+Left).id == -1) dejar_comida[(p).i][(p+Left).j] = true;
		else if (pos_ok(p+Right) and cell(p+Right).type != Water and cell(p+Right).bonus != None and cell(p+Right).id == -1) dejar_comida[(p).i][(p+Right).j] = true;
	}
	// si a casilla adyacente de la reina hay bonus voy a por bonus
	void reina_a_bonus (Ant a, vector<vector<bool>>& no_os_mateis_gracias, vector<vector<bool>>& dejar_comida) {
		if (cell(a.pos+Up).bonus != None and cell(a.pos+Up).id == -1 and dejar_comida[(a.pos+Up).i][a.pos.j] == true) hay_que_moverse(a.pos, Up, a.id, no_os_mateis_gracias);
		else if (cell(a.pos+Down).bonus != None  and cell(a.pos+Down).id == -1 and dejar_comida[(a.pos+Down).i][a.pos.j] == true) hay_que_moverse(a.pos, Down, a.id, no_os_mateis_gracias);
		else if (cell(a.pos+Left).bonus != None and cell(a.pos+Left).id == -1 and dejar_comida[(a.pos).i][(a.pos+Left).j] == true) hay_que_moverse(a.pos, Left, a.id, no_os_mateis_gracias);
		else if (cell(a.pos+Right).bonus != None and cell(a.pos+Right).id == -1 and dejar_comida[(a.pos).i][(a.pos+Right).j] == true) hay_que_moverse(a.pos, Right, a.id, no_os_mateis_gracias);
	}
	// valor absoluto
	int distancia_calc (Pos p1, Pos p2) {
		int i, j;
		if (p1.i >= p2.i) i = p1.i - p2.i;
		else i = p2.i - p1.i;
		if (p1.j >= p2.j) j = p1.j - p2.j;
		else j = p2.j - p1.j;
		return i + j;
	}
	bool casilla (Pos p, int my_queen_id) {
		if (pos_ok(p+Up) and cell(p+Up).type != Water and cell(p+Up).id == my_queen_id) return true;
        if (pos_ok(p+Down) and cell(p+Down).type != Water and cell(p+Down).id == my_queen_id) return true;
        if (pos_ok(p+Left) and cell(p+Left).type != Water and cell(p+Left).id == my_queen_id) return true;
        if (pos_ok(p+Right) and cell(p+Right).type != Water and cell(p+Right).id == my_queen_id) return true;
        if (pos_ok(p+Up+Up) and cell(p+Up+Up).type != Water and cell(p+Up+Up).id == my_queen_id) return true;
        if (pos_ok(p+Up+Left) and cell(p+Up+Left).type != Water and cell(p+Up+Left).id == my_queen_id) return true;
        if (pos_ok(p+Up+Right) and cell(p+Up+Right).type != Water and cell(p+Up+Right).id == my_queen_id) return true;
        if (pos_ok(p+Left+Left) and cell(p+Left+Left).type != Water and cell(p+Left+Left).id == my_queen_id) return true;
        if (pos_ok(p+Right+Right) and cell(p+Right+Right).type != Water and cell(p+Right+Right).id == my_queen_id) return true;
        if (pos_ok(p+Down+Down) and cell(p+Down+Down).type != Water and cell(p+Down+Down).id == my_queen_id) return true;
        if (pos_ok(p+Down+Right) and cell(p+Down+Right).type != Water and cell(p+Down+Right).id == my_queen_id) return true;
        if (pos_ok(p+Down+Left) and cell(p+Down+Left).type != Water and cell(p+Down+Left).id == my_queen_id) return true;
        return false;
	}
	/**
	* Play method, invoked once per each round.
	*/
	
	virtual void play () {
		vector<int> workers_ids = workers(me());
		vector<int> soldiers_ids = soldiers(me());
		vector<int> queen_id = queens(me());
		vector<vector<bool>> no_os_mateis_gracias(board_rows(), vector<bool>(board_cols(),false));
		vector<vector<bool>> dejar_comida(board_rows(), vector<bool>(board_cols(),false)); 		// la ronda despues e dejar la comida se resetea

		
		// queen
		Dir dir, dir2;
		int dist, dist2;
		int my_queen_id = queen_id[0];
		Ant a3 = ant(my_queen_id);
		Pos p3 = a3.pos;
		no_os_mateis_gracias[p3.i][p3.j] = true;
			
		if (num_rounds() % queen_period() == 0) {
			bloquear(p3, dejar_comida);
			reina_a_bonus(a3, no_os_mateis_gracias, dejar_comida);
			bool bonus = bfs_a_hormigas_con_bonus(p3, dir, dist, no_os_mateis_gracias); 
			if (not bonus) bonus = bfs_a_bonus_reina(p3, dir, dist, no_os_mateis_gracias);
			bool enemigo = bfs_a_enemigos2(p3, dir2, dist2, no_os_mateis_gracias); 
				
			lay_eggs(a3, int(workers_ids.size()), int(soldiers_ids.size()));
			if (bonus and enemigo) dnd_voy_al_final(p3, my_queen_id, dir, dist, dir2, dist2, no_os_mateis_gracias);
			else if (bonus and not enemigo)	{
				if (cell(p3+dir).id == -1) hay_que_moverse(p3, dir, my_queen_id, no_os_mateis_gracias);
			}
			else if (enemigo and not bonus) {
				if (cell(p3+dir2).id == -1 or sies(p3+dir)) hay_que_moverse(p3, dir2, my_queen_id, no_os_mateis_gracias);	
			} 
		}	
		// workers	
		for (int i = 0; i < int(workers_ids.size()); ++i) { 
			int worker_id = workers_ids[i];
			Ant a1 = ant(worker_id);
			Pos p1 = a1.pos;
			int my_queen_id = queen_id[0];
			Dir dir;
			int dist;
			no_os_mateis_gracias[p1.i][p1.j] = true;
			
			if (distancia_calc(p1, p3) <= 2) dejar_comida[p1.i][p1.j] = true;
			
			if (a1.life == 1) leave(cell(p1).id);
			// no tengo bonus 
			else if (a1.bonus == None) {
				if (cell(p1).bonus != None and not dejar_comida[p1.i][p1.j]) take(cell(p1).id); 
				else if (bfs_a_bonus(p1, dir, dist, dejar_comida, no_os_mateis_gracias)) hay_que_moverse(p1, dir, worker_id, no_os_mateis_gracias);
				
			}
			// tengo bonus y si p1+dir es reina lo dejo, sino muevo a buscar la reina
			else if (a1.bonus != None) {
				if (distancia_calc(p1, p3) <= 2) leave(cell(p1).id);
				else if (bfs_a_historia(p1, my_queen_id, dir, dist, no_os_mateis_gracias)) {
						hay_que_moverse(p1, dir, worker_id, no_os_mateis_gracias);
						dejar_comida[p1.i][p1.j] = true;
				}
				/*
				else {
					Dir dir1 = Dir(random(0,3));
					if (pos_ok(p1+dir1) and cell(p1+dir1).type != Water and cell(p1+dir1).id == -1) hay_que_moverse(p1, dir1, worker_id, no_os_mateis_gracias);
				}
				*/
			}
		}
		// soldiers
		for (int i = 0; i < int(soldiers_ids.size()); ++i) {
			int soldier_id = soldiers_ids[i];
			Ant a2 = ant(soldier_id);
			Pos p2 = a2.pos;
			Dir dir;
			int dist;
			no_os_mateis_gracias[p2.i][p2.j] = true;

			if (bfs_a_enemigos(p2, dir, dist, no_os_mateis_gracias)) hay_que_moverse(p2, dir, soldier_id, no_os_mateis_gracias);
		}		
	}
};



/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);


