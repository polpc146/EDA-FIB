#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME CataIanboy2


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

  //                E  S   W   N
  vector<int> di = {0, 1,  0, -1};
  vector<int> dj = {1, 0, -1,  0};
  
  bool move_dir (Ant mi_hormiga, Dir direccion, vector<vector<int>>& huecos_ocupados) {
      
      Pos posicion = mi_hormiga.pos + direccion;
      bool ocupado = false;
      for (auto x : huecos_ocupados[posicion.i]) {
                          
            if (x == posicion.j) ocupado = true;
      }
      if (not ocupado) {
                
            huecos_ocupados[posicion.i].push_back(posicion.j);
            move (mi_hormiga.id,direccion);
            return true;
      }
      return false;
  }
  
  bool condiciones_cuadrante(int i, int j) {
      
      if (me() == 0) {
          
          if (i > 15 or j > 15) return false;
      }
      else if (me() == 1) {
          
          if (i > 15 or j <= 10) return false;
      }
      else if (me() == 2) {
          
          if (i <= 10 or j <= 10) return false;
      }
      else if (me() == 3) {
          
          if (i <= 10 or j > 15) return false;
      }
      return true;
  }
  
  bool move_a_favor (Ant my_worker, Pos posicion, vector<vector<int>>& huecos_ocupados) {
      
      Cell movimiento;
              if (posicion.i < my_worker.pos.i){
                  
                  movimiento = cell(my_worker.pos.i -1, my_worker.pos.j);
                  if (movimiento.id == -1 and movimiento.type == Soil and condiciones_cuadrante(my_worker.pos.i -1, my_worker.pos.j)) {
                      
                      if(move_dir (my_worker, Up, huecos_ocupados)) return true;
                }
            }
            if (posicion.i > my_worker.pos.i){
                  
                  movimiento = cell(my_worker.pos.i +1, my_worker.pos.j);
                  if (movimiento.id == -1 and movimiento.type == Soil and condiciones_cuadrante(my_worker.pos.i +1, my_worker.pos.j)) {
                      
                      if(move_dir (my_worker, Down, huecos_ocupados)) return true;
                }
            }
            if (posicion.j < my_worker.pos.j){
                  
                  movimiento = cell(my_worker.pos.i, my_worker.pos.j -1);
                  if (movimiento.id == -1 and movimiento.type == Soil and condiciones_cuadrante(my_worker.pos.i, my_worker.pos.j -1)) {
                      
                      if(move_dir (my_worker, Left, huecos_ocupados)) return true;
                }
            }
            if (posicion.j > my_worker.pos.j){
                  
                  movimiento = cell(my_worker.pos.i, my_worker.pos.j +1);
                  if (movimiento.id == -1 and movimiento.type == Soil and condiciones_cuadrante(my_worker.pos.i, my_worker.pos.j +1)) {
                      
                      if(move_dir (my_worker, Right, huecos_ocupados)) return true;
                }
            }
        return false;
  }
  
  bool move_en_contra (Ant my_worker, Pos posicion, vector<vector<int>>& huecos_ocupados) {
      
      Cell movimiento;
              if (posicion.i < my_worker.pos.i){
                  
                  movimiento = cell(my_worker.pos.i +1, my_worker.pos.j);
                  if (movimiento.id == -1 and movimiento.type == Soil and condiciones_cuadrante(my_worker.pos.i +1, my_worker.pos.j) and my_worker.pos.i +1 >= 0 and my_worker.pos.i +1 < board_rows() and my_worker.pos.j >= 0 and my_worker.pos.j < board_cols()) {
                      
                      if(move_dir (my_worker, Down, huecos_ocupados)) return true;
                }
                movimiento = cell(my_worker.pos.i, my_worker.pos.j +1);
                  if (movimiento.id == -1 and movimiento.type == Soil and condiciones_cuadrante(my_worker.pos.i, my_worker.pos.j +1) and my_worker.pos.i >= 0 and my_worker.pos.i < board_rows() and my_worker.pos.j +1 >= 0 and my_worker.pos.j +1 < board_cols()) {
                      
                      if(move_dir (my_worker, Right, huecos_ocupados)) return true;
                }
                 movimiento = cell(my_worker.pos.i, my_worker.pos.j -1);
                  if (movimiento.id == -1 and movimiento.type == Soil and condiciones_cuadrante(my_worker.pos.i, my_worker.pos.j -1) and my_worker.pos.i >= 0 and my_worker.pos.i < board_rows() and my_worker.pos.j -1 >= 0 and my_worker.pos.j -1 < board_cols()) {
                      
                      if(move_dir (my_worker, Left, huecos_ocupados)) return true;
                }
            }
            if (posicion.i > my_worker.pos.i){
                  
                movimiento = cell(my_worker.pos.i -1, my_worker.pos.j);
                  if (movimiento.id == -1 and movimiento.type == Soil and condiciones_cuadrante(my_worker.pos.i -1, my_worker.pos.j) and my_worker.pos.i -1 >= 0 and my_worker.pos.i -1 < board_rows() and my_worker.pos.j >= 0 and my_worker.pos.j < board_cols()) {
                      
                      if(move_dir (my_worker, Up, huecos_ocupados)) return true;
                }
                 movimiento = cell(my_worker.pos.i, my_worker.pos.j +1);
                  if (movimiento.id == -1 and movimiento.type == Soil and condiciones_cuadrante(my_worker.pos.i, my_worker.pos.j +1) and my_worker.pos.i >= 0 and my_worker.pos.i < board_rows() and my_worker.pos.j +1 >= 0 and my_worker.pos.j +1 < board_cols()) {
                      
                      if(move_dir (my_worker, Right, huecos_ocupados)) return true;
                }
                 movimiento = cell(my_worker.pos.i, my_worker.pos.j -1);
                  if (movimiento.id == -1 and movimiento.type == Soil and condiciones_cuadrante(my_worker.pos.i, my_worker.pos.j -1) and my_worker.pos.i >= 0 and my_worker.pos.i < board_rows() and my_worker.pos.j -1 >= 0 and my_worker.pos.j -1 < board_cols()) {
                      
                      if(move_dir (my_worker, Left, huecos_ocupados)) return true;
                }
            }
            if (posicion.j < my_worker.pos.j){
                  
                movimiento = cell(my_worker.pos.i, my_worker.pos.j +1);
                  if (movimiento.id == -1 and movimiento.type == Soil and condiciones_cuadrante(my_worker.pos.i, my_worker.pos.j +1) and my_worker.pos.i >= 0 and my_worker.pos.i < board_rows() and my_worker.pos.j +1 >= 0 and my_worker.pos.j +1 < board_cols()) {
                      
                      if(move_dir (my_worker, Right, huecos_ocupados)) return true;
                }
                movimiento = cell(my_worker.pos.i -1, my_worker.pos.j);
                  if (movimiento.id == -1 and movimiento.type == Soil and condiciones_cuadrante(my_worker.pos.i -1, my_worker.pos.j) and my_worker.pos.i -1 >= 0 and my_worker.pos.i -1 < board_rows() and my_worker.pos.j >= 0 and my_worker.pos.j < board_cols()) {
                      
                      if(move_dir (my_worker, Up, huecos_ocupados)) return true;
                }
                movimiento = cell(my_worker.pos.i +1, my_worker.pos.j);
                  if (movimiento.id == -1 and movimiento.type == Soil and condiciones_cuadrante(my_worker.pos.i +1, my_worker.pos.j) and my_worker.pos.i +1 >= 0 and my_worker.pos.i +1 < board_rows() and my_worker.pos.j >= 0 and my_worker.pos.j < board_cols()) {
                      
                      if(move_dir (my_worker, Down, huecos_ocupados)) return true;
                }
            }
            if (posicion.j > my_worker.pos.j){
                  
                movimiento = cell(my_worker.pos.i, my_worker.pos.j -1);
                  if (movimiento.id == -1 and movimiento.type == Soil and condiciones_cuadrante(my_worker.pos.i, my_worker.pos.j -1) and my_worker.pos.i >= 0 and my_worker.pos.i < board_rows() and my_worker.pos.j -1 >= 0 and my_worker.pos.j -1 < board_cols()) {
                      
                      if(move_dir (my_worker, Left, huecos_ocupados)) return true;
                }
                 movimiento = cell(my_worker.pos.i -1, my_worker.pos.j);
                  if (movimiento.id == -1 and movimiento.type == Soil and condiciones_cuadrante(my_worker.pos.i -1, my_worker.pos.j) and my_worker.pos.i -1 >= 0 and my_worker.pos.i -1 < board_rows() and my_worker.pos.j >= 0 and my_worker.pos.j < board_cols()) {
                      
                      if(move_dir (my_worker, Up, huecos_ocupados)) return true;
                }
                movimiento = cell(my_worker.pos.i +1, my_worker.pos.j);
                  if (movimiento.id == -1 and movimiento.type == Soil and condiciones_cuadrante(my_worker.pos.i +1, my_worker.pos.j) and my_worker.pos.i +1 >= 0 and my_worker.pos.i +1 < board_rows() and my_worker.pos.j >= 0 and my_worker.pos.j < board_cols()) {
                      
                      if(move_dir (my_worker, Down, huecos_ocupados)) return true;
                }
            }
        return false;
  }
  
  bool move_random (Ant my_worker, vector<vector<int>>& huecos_ocupados) {
      
      vector<int> aleatorio = random_permutation(4);
      Cell movimiento;
      for (int i = 0; i < 4; ++i) {
         
          if (aleatorio[i] == Up) {
              
              movimiento = cell(my_worker.pos + Up);
              if (movimiento.id == -1 and movimiento.type == Soil and condiciones_cuadrante(my_worker.pos.i -1, my_worker.pos.j) and my_worker.pos.i -1 >= 0 and my_worker.pos.i -1 < board_rows() and my_worker.pos.j >= 0 and my_worker.pos.j < board_cols()) {
                  
                  if(move_dir (my_worker, Up, huecos_ocupados)) return true;
              }
          }
          else if (aleatorio[i] == Down) {
              
              movimiento = cell(my_worker.pos + Down);
              if (movimiento.id == -1 and movimiento.type == Soil and condiciones_cuadrante(my_worker.pos.i +1, my_worker.pos.j) and my_worker.pos.i +1 >= 0 and my_worker.pos.i +1 < board_rows() and my_worker.pos.j >= 0 and my_worker.pos.j < board_cols()) {
                  
                  if(move_dir (my_worker, Down, huecos_ocupados)) return true;
              }
          }
          else if (aleatorio[i] == Left) {
              
              movimiento = cell(my_worker.pos + Left);
              if (movimiento.id == -1 and movimiento.type == Soil and condiciones_cuadrante(my_worker.pos.i, my_worker.pos.j -1) and my_worker.pos.i >= 0 and my_worker.pos.i < board_rows() and my_worker.pos.j -1 >= 0 and my_worker.pos.j -1 < board_cols()) {
                  
                  if(move_dir (my_worker, Left, huecos_ocupados)) return true;
              }
          }
          else if (aleatorio[i] == Right) {
              
              movimiento = cell(my_worker.pos + Right);
              if (movimiento.id == -1 and movimiento.type == Soil and condiciones_cuadrante(my_worker.pos.i, my_worker.pos.j +1) and my_worker.pos.i >= 0 and my_worker.pos.i < board_rows() and my_worker.pos.j +1 >= 0 and my_worker.pos.j +1 < board_cols()) {
                  
                  if(move_dir (my_worker, Right, huecos_ocupados)) return true;
              }
          }
      }
      return false;
  }
  
  bool mama_a_la_vista (Ant my_worker, Ant mi_mama) {
      
      int n = board_rows();
      int m = board_cols();
      vector<vector<int>> visitados(n);
      queue<pair<int,int>> cola;
      cola.push({my_worker.pos.i, my_worker.pos.j});
      visitados[my_worker.pos.i].push_back(my_worker.pos.j);
      int distancia = 0;
      while (not cola.empty() and distancia < 3) {
          
          auto i = cola.front().first;
          auto j = cola.front().second;
          cola.pop();
          for (int k = 0; k < 4; ++k) {
              
              int ii = i + di[k];
              int jj = j + dj[k];
              Cell casilla = cell(ii, jj);
              if (ii >= 0 and ii < n and jj >= 0 and jj < m and casilla.type == Soil) {
                  
                  bool visitado = false;
                  for (auto x : visitados[ii]) {
                      
                      if (x == jj) visitado = true;
                  }
                  if (not visitado) {
                      
                     if (casilla.id != -1) {
                      
                      Ant mami = ant(casilla.id);
                      if (mami.id == mi_mama.id) return true;
                  } 
                  cola.push({ii,jj});
                  visitados[ii].push_back(jj); 
                }
            }
        }
        ++distancia;
    }
    return false;
  }
  
  pair<bool,Pos> moros_en_la_costa (Ant my_worker) {
      
      int n = board_rows();
      int m = board_cols();
      vector<vector<int>> visitados(n);
      queue<pair<int,int>> cola;
      cola.push({my_worker.pos.i, my_worker.pos.j});
      visitados[my_worker.pos.i].push_back(my_worker.pos.j);
      int distancia = 0;
      pair<bool,Pos> hay_alguien_malo;
      while (not cola.empty() and distancia < 2) {
          
          auto i = cola.front().first;
          auto j = cola.front().second;
          cola.pop();
          for (int k = 0; k < 4; ++k) {
              
              int ii = i + di[k];
              int jj = j + dj[k];
              Cell casilla = cell(ii, jj);
              if (ii >= 0 and ii < n and jj >= 0 and jj < m and casilla.type == Soil) {
                  
                  bool visitado = false;
                  for (auto x : visitados[ii]) {
                      
                      if (x == jj) visitado = true;
                  }
                  if (not visitado) {
                      
                     if (casilla.id != -1) {
                      
                      Ant que_te_lo_crees_tu = ant(casilla.id);
                      if (que_te_lo_crees_tu.player != me()) {
                          
                          hay_alguien_malo.first = true;
                          Pos posicion(ii,jj);
                          hay_alguien_malo.second = posicion;
                          return hay_alguien_malo;
                    }
                  } 
                  cola.push({ii,jj});
                  visitados[ii].push_back(jj); 
                }
            }
        }
        ++distancia;
    }
    hay_alguien_malo.first = false;
    Pos posicion(-1,-1);
    hay_alguien_malo.second = posicion;
    return hay_alguien_malo;
  }
  
  bool hormigas_suicidas (Ant my_worker, vector<vector<int>>& huecos_ocupados) {
      
    Cell matar;
    matar = cell(my_worker.pos.i -1, my_worker.pos.j);
    if (matar.id != -1) {
        
        Ant sacrificio = ant(matar.id);
        if (sacrificio.player != me()) {
            
            if(move_dir (my_worker, Up, huecos_ocupados)) return true;    
        }
    }
    matar = cell(my_worker.pos.i +1, my_worker.pos.j);
    if (matar.id != -1) {
        
        Ant sacrificio = ant(matar.id);
        if (sacrificio.player != me()) {
            
            if(move_dir (my_worker, Down, huecos_ocupados)) return true;
        }
    }
    matar = cell(my_worker.pos.i, my_worker.pos.j -1);
    if (matar.id != -1) {
        
        Ant sacrificio = ant(matar.id);
        if (sacrificio.player != me()) {
            
            if(move_dir (my_worker, Left, huecos_ocupados)) return true;
        }
    }
    matar = cell(my_worker.pos.i, my_worker.pos.j +1);
    if (matar.id != -1) {
        
        Ant sacrificio = ant(matar.id);
        if (sacrificio.player != me()) {
            
            if(move_dir (my_worker, Right, huecos_ocupados)) return true;
        }
    }
    return false;
  }
  
  Pos buscar_bonus (Ant my_worker) {
      
      int n = board_rows();
      int m = board_cols();
      vector<vector<bool>> visitados(n, vector<bool>(m, false));
      queue<pair<int,int>> cola;
      cola.push({my_worker.pos.i, my_worker.pos.j});
      visitados[my_worker.pos.i][my_worker.pos.j] = true;
      while (not cola.empty()) {
          
          auto i = cola.front().first;
          auto j = cola.front().second;
          cola.pop();
          for (int k = 0; k < 4; ++k) {
              
              int ii = i + di[k];
              int jj = j + dj[k];
              Cell casilla = cell(ii, jj);
              if (ii >= 0 and ii < n and jj >= 0 and jj < m and visitados[ii][jj] == false and casilla.type == Soil) {
                  
                  if (casilla.bonus != None) {
                      
                      Pos posicion(ii,jj);
                      return posicion;
                }
                  cola.push({ii,jj});
                  visitados[ii][jj] = true;
            }
        }
    }
    Pos vacio(-1,-1);
    return vacio;
  }
  
  void bfs_trabajadoras (int id_worker, vector<vector<int>>& huecos_ocupados) {
      
      Ant my_worker = ant(id_worker);
      Cell my_cell = cell(my_worker.pos);
      vector<int> mama = queens(me());
      Ant mi_mama = ant(mama[0]);
      bool veo_a_mama = mama_a_la_vista(my_worker, mi_mama);
      pair<bool,Pos> hay_alguien_malo = moros_en_la_costa(my_worker);
      // WORKER CON 1 DE VIDA
    if (my_worker.life == 1) {
        
        if (my_worker.bonus == None) {
            
            if(hormigas_suicidas(my_worker, huecos_ocupados)) return;
        }
        else {
            
            if (not hay_alguien_malo.first) {
                
                leave(id_worker);
                return;
            }
            else if(hormigas_suicidas(my_worker, huecos_ocupados)) return;
        }
        return;
    }
      //COGER BONUS O HUIR DE LA REINA
      if (my_cell.bonus != None and my_worker.bonus == None) {
          
          if (not veo_a_mama) {
              
              take(id_worker);
              return;
          }
          else {
              
              if(move_en_contra(my_worker, mi_mama.pos, huecos_ocupados)) return;
          }
      }
      //HUIR SI HAY ALGUIEN MALO 
    if (hay_alguien_malo.first) {
        
        if(move_en_contra(my_worker, hay_alguien_malo.second, huecos_ocupados)) return;
    }
    //LA REINA ESTA CERCA
      if (round() > 10){
        if (veo_a_mama) {
          
          if (my_worker.bonus != None) {
              
              leave (id_worker);
              return;
            }
            else {
                
                
              if(move_en_contra(my_worker, mi_mama.pos, huecos_ocupados)) return;
            }
        }
      }
      //BUSCO BONUS Y MUEVO WORKER SI PUEDO
      if (my_worker.bonus == None and my_worker.life > 1) {
          
          Pos pos_bonus = buscar_bonus(my_worker);
          Pos vacio(-1,-1);
          if (pos_bonus != vacio) {
              
              if(move_a_favor(my_worker, pos_bonus, huecos_ocupados)) return;
        }
        //NO HAY BONUS O HORMIGA NO SE PUEDE MOVER O SE ALEJA DEMASIADO DE LA HORMIGUERA
        if(move_a_favor(my_worker, mi_mama.pos, huecos_ocupados)) return;
     }
     //BUSCAR A LA REINA
   if (my_worker.bonus != None) {
        
        if(move_a_favor(my_worker, mi_mama.pos, huecos_ocupados)) return;
    }
    //MOVIMIENTO ALEATORIO
    if(move_random(my_worker, huecos_ocupados)) return;
  }
  
  bool puedo_comer (Ant my_queen, vector<vector<int>>& huecos_ocupados) {
      
    Cell comida;
    comida = cell(my_queen.pos.i -1, my_queen.pos.j);
    if (comida.id == -1 and comida.bonus != None) {
                
                huecos_ocupados[my_queen.pos.i -1].push_back(my_queen.pos.j);
                move (my_queen.id,Up);
                return true;
    }
    comida = cell(my_queen.pos.i +1, my_queen.pos.j);
    if (comida.id == -1 and comida.bonus != None) {
                
                huecos_ocupados[my_queen.pos.i +1].push_back(my_queen.pos.j);
                move (my_queen.id,Down);
                return true;
    }
    comida = cell(my_queen.pos.i, my_queen.pos.j -1);
    if (comida.id == -1 and comida.bonus != None) {
                
                huecos_ocupados[my_queen.pos.i].push_back(my_queen.pos.j -1);
                move (my_queen.id,Left);
                return true;
    }
    comida = cell(my_queen.pos.i, my_queen.pos.j +1);
    if (comida.id == -1 and comida.bonus != None) {
                
                huecos_ocupados[my_queen.pos.i].push_back(my_queen.pos.j +1);
                move (my_queen.id,Right);
                return true;
    }
    return false;
  }
  
  bool puedo_matar (Ant my_queen, vector<vector<int>>& huecos_ocupados) {
      
    Cell matar;
    matar = cell(my_queen.pos.i -1, my_queen.pos.j);
    if (matar.id != -1) {
                
        Ant sacrificio = ant(matar.id);
        if (sacrificio.player != me() and sacrificio.type != Queen) {
                
                huecos_ocupados[my_queen.pos.i -1].push_back(my_queen.pos.j);
                move (my_queen.id,Up);
                return true;
        }
    }
    matar = cell(my_queen.pos.i +1, my_queen.pos.j);
    if (matar.id != -1) {
                
        Ant sacrificio = ant(matar.id);
        if (sacrificio.player != me() and sacrificio.type != Queen) {
            
                huecos_ocupados[my_queen.pos.i +1].push_back(my_queen.pos.j);
                move (my_queen.id,Down);
                return true;
        }
    }
    matar = cell(my_queen.pos.i, my_queen.pos.j -1);
    if (matar.id != -1) {
                
        Ant sacrificio = ant(matar.id);
        if (sacrificio.player != me() and sacrificio.type != Queen) {

                huecos_ocupados[my_queen.pos.i].push_back(my_queen.pos.j -1);
                move (my_queen.id,Left);
                return true;
        }
    }
    matar = cell(my_queen.pos.i, my_queen.pos.j +1);
    if (matar.id != -1) {
                
        Ant sacrificio = ant(matar.id);
        if (sacrificio.player != me() and sacrificio.type != Queen) {
            

                huecos_ocupados[my_queen.pos.i].push_back(my_queen.pos.j +1);
                move (my_queen.id,Right);
                return true;
        }
    }
    return false;
  }
  
  Pos buscar_comida (Ant my_queen) {
      
      int n = board_rows();
      int m = board_cols();
      vector<vector<bool>> visitados(n, vector<bool>(m, false));
      queue<pair<int,int>> cola;
      cola.push({my_queen.pos.i, my_queen.pos.j});
      visitados[my_queen.pos.i][my_queen.pos.j] = true;
      while (not cola.empty()) {
          
          auto i = cola.front().first;
          auto j = cola.front().second;
          cola.pop();
          for (int k = 0; k < 4; ++k) {
              
              int ii = i + di[k];
              int jj = j + dj[k];
              Cell casilla = cell(ii, jj);
              if (ii >= 0 and ii < n and jj >= 0 and jj < m and visitados[ii][jj] == false and casilla.type == Soil) {
                  
                  if (casilla.id != -1) {
                      
                      Ant mi_hormiga = ant (casilla.id);
                      if (mi_hormiga.player == me() and mi_hormiga.bonus != None){
                          
                          Pos posicion(ii,jj);
                          return posicion;
                    }
                }
                  cola.push({ii,jj});
                  visitados[ii][jj] = true;
            }
        }
    }
    Pos vacio(-1,-1);
    return vacio;
  }
  
  void bfs_reina (int id_queen, vector<vector<int>>& huecos_ocupados) {
      
      Ant my_queen = ant(id_queen);
      //LA REINA SE PUEDE MOVER
      if (round() % queen_period() == 0) {
          
          if (puedo_comer(my_queen, huecos_ocupados)) return;
          if (puedo_matar(my_queen, huecos_ocupados)) return;
          Pos pos_comida = buscar_comida(my_queen);
          Pos vacio(-1,-1);
        if (pos_comida != vacio) {
            
            if(move_a_favor(my_queen, pos_comida, huecos_ocupados)) return;
        }
          Pos pos_bonus = buscar_bonus(my_queen);
          if (pos_bonus != vacio) {
              
              if(move_a_favor(my_queen, pos_bonus, huecos_ocupados)) return;
        }
     }
     //PONER HUEVOS
     if (round() > 24) {
         
        int carbohidratos = my_queen.reserve[0];
        int proteinas = my_queen.reserve[1];
        int lipidos = my_queen.reserve[2];
        vector<int> mis_soldados = soldiers(me());
        if (mis_soldados.size() < 3 and carbohidratos >= soldier_carbo() and proteinas >= soldier_prote() and lipidos >= soldier_lipid()) {
            
            Cell huevo;
                  huevo = cell(my_queen.pos.i -1, my_queen.pos.j);
                  if (huevo.id == -1 and huevo.type == Soil and condiciones_cuadrante(my_queen.pos.i -1, my_queen.pos.j) and my_queen.pos.i -1 >= 0 and my_queen.pos.i -1 < board_rows() and my_queen.pos.j >= 0 and my_queen.pos.j < board_cols()) {
                        
                        huecos_ocupados[my_queen.pos.i -1].push_back(my_queen.pos.j);
                        lay (id_queen, Up, Soldier);
                        return;
                }
                  huevo= cell(my_queen.pos.i +1, my_queen.pos.j);
                  if (huevo.id == -1 and huevo.type == Soil and condiciones_cuadrante(my_queen.pos.i +1, my_queen.pos.j) and my_queen.pos.i +1 >= 0 and my_queen.pos.i +1 < board_rows() and my_queen.pos.j >= 0 and my_queen.pos.j < board_cols()) {
                        
                        huecos_ocupados[my_queen.pos.i +1].push_back(my_queen.pos.j);
                        lay (id_queen, Down, Soldier);
                        return;
                }
                  huevo = cell(my_queen.pos.i, my_queen.pos.j -1);
                  if (huevo.id == -1 and huevo.type == Soil and condiciones_cuadrante(my_queen.pos.i, my_queen.pos.j -1) and my_queen.pos.i >= 0 and my_queen.pos.i < board_rows() and my_queen.pos.j -1 >= 0 and my_queen.pos.j -1 < board_cols()) {
                        
                        huecos_ocupados[my_queen.pos.i].push_back(my_queen.pos.j -1);
                        lay (id_queen, Left, Soldier);
                        return;
                } 
                  huevo = cell(my_queen.pos.i, my_queen.pos.j +1);
                  if (huevo.id == -1 and huevo.type == Soil and condiciones_cuadrante(my_queen.pos.i, my_queen.pos.j +1) and my_queen.pos.i >= 0 and my_queen.pos.i < board_rows() and my_queen.pos.j +1 >= 0 and my_queen.pos.j +1 < board_cols()) {
                        
                        huecos_ocupados[my_queen.pos.i].push_back(my_queen.pos.j +1);
                        lay (id_queen, Right, Soldier);
                        return;
                }
        }
        if (carbohidratos >= worker_carbo() and proteinas >= worker_prote() and lipidos >= worker_lipid()) {
            
            Cell huevo;
                  huevo = cell(my_queen.pos.i -1, my_queen.pos.j);
                  if (huevo.id == -1 and huevo.type == Soil and condiciones_cuadrante(my_queen.pos.i -1, my_queen.pos.j) and my_queen.pos.i -1 >= 0 and my_queen.pos.i -1 < board_rows() and my_queen.pos.j >= 0 and my_queen.pos.j < board_cols()) {
                        
                        huecos_ocupados[my_queen.pos.i -1].push_back(my_queen.pos.j);
                        lay (id_queen, Up, Worker);
                        return;
                }
                  huevo= cell(my_queen.pos.i +1, my_queen.pos.j);
                  if (huevo.id == -1 and huevo.type == Soil and condiciones_cuadrante(my_queen.pos.i +1, my_queen.pos.j) and my_queen.pos.i +1 >= 0 and my_queen.pos.i +1 < board_rows() and my_queen.pos.j >= 0 and my_queen.pos.j < board_cols()) {
                        
                        huecos_ocupados[my_queen.pos.i +1].push_back(my_queen.pos.j);
                        lay (id_queen, Down, Worker);
                        return;
                }
                  huevo = cell(my_queen.pos.i, my_queen.pos.j -1);
                  if (huevo.id == -1 and huevo.type == Soil and condiciones_cuadrante(my_queen.pos.i, my_queen.pos.j -1) and my_queen.pos.i >= 0 and my_queen.pos.i < board_rows() and my_queen.pos.j -1 >= 0 and my_queen.pos.j -1 < board_cols()) {
                        
                        huecos_ocupados[my_queen.pos.i].push_back(my_queen.pos.j -1);
                        lay (id_queen, Left, Worker);
                        return;
                } 
                  huevo = cell(my_queen.pos.i, my_queen.pos.j +1);
                  if (huevo.id == -1 and huevo.type == Soil and condiciones_cuadrante(my_queen.pos.i, my_queen.pos.j +1) and my_queen.pos.i >= 0 and my_queen.pos.i < board_rows() and my_queen.pos.j +1 >= 0 and my_queen.pos.j +1 < board_cols()) {
                        
                        huecos_ocupados[my_queen.pos.i].push_back(my_queen.pos.j +1);
                        lay (id_queen, Right, Worker);
                        return;
                }
        }
    }
    //MOVIMIENTO ALEATORIO
    if (round() % queen_period() == 0) {
        
        if(move_random(my_queen, huecos_ocupados)) return;
    }
  }
  
  bool todo_por_la_patria (Ant my_soldier, vector<vector<int>>& huecos_ocupados) {
      
    Cell matar;
    matar = cell(my_soldier.pos.i -1, my_soldier.pos.j);
    if (matar.id != -1) {
        
        Ant sacrificio = ant(matar.id);
        if (sacrificio.player != me() and sacrificio.type != Queen) {
            
            if(move_dir(my_soldier, Up, huecos_ocupados)) return true;
        }
    }
    matar = cell(my_soldier.pos.i +1, my_soldier.pos.j);
    if (matar.id != -1) {
        
        Ant sacrificio = ant(matar.id);
        if (sacrificio.player != me() and sacrificio.type != Queen) {
            
            if(move_dir(my_soldier, Down, huecos_ocupados)) return true;
        }
    }
    matar = cell(my_soldier.pos.i, my_soldier.pos.j -1);
    if (matar.id != -1) {
        
        Ant sacrificio = ant(matar.id);
        if (sacrificio.player != me() and sacrificio.type != Queen) {
            
            if(move_dir(my_soldier, Left, huecos_ocupados)) return true;
        }
    }
    matar = cell(my_soldier.pos.i, my_soldier.pos.j +1);
    if (matar.id != -1) {
        
        Ant sacrificio = ant(matar.id);
        if (sacrificio.player != me() and sacrificio.type != Queen) {
            
            if(move_dir(my_soldier, Right, huecos_ocupados)) return true;
        }
    }
    return false;
  }
  
  bool matar_matar_y_matar (Ant my_soldier, vector<vector<int>>& huecos_ocupados) {
      
    Cell matar;
    matar = cell(my_soldier.pos.i -1, my_soldier.pos.j);
    if (matar.id != -1) {
        
        Ant sacrificio = ant(matar.id);
        if (sacrificio.player != me() and sacrificio.type == Worker) {
            
            if(move_dir(my_soldier, Up, huecos_ocupados)) return true;
        }
    }
    matar = cell(my_soldier.pos.i +1, my_soldier.pos.j);
    if (matar.id != -1) {
        
        Ant sacrificio = ant(matar.id);
        if (sacrificio.player != me() and sacrificio.type == Worker) {
            
            if(move_dir(my_soldier, Down, huecos_ocupados)) return true;
        }
    }
    matar = cell(my_soldier.pos.i, my_soldier.pos.j -1);
    if (matar.id != -1) {
        
        Ant sacrificio = ant(matar.id);
        if (sacrificio.player != me() and sacrificio.type == Worker) {
            
            if(move_dir(my_soldier, Left, huecos_ocupados)) return true;
        }
    }
    matar = cell(my_soldier.pos.i, my_soldier.pos.j +1);
    if (matar.id != -1) {
        
        Ant sacrificio = ant(matar.id);
        if (sacrificio.player != me() and sacrificio.type == Worker) {
            
            if(move_dir(my_soldier, Right, huecos_ocupados)) return true;
        }
    }
    return false;
  }
  
  Pos buscar_hormiga (Ant my_soldier) {
      
      int n = board_rows();
      int m = board_cols();
      vector<vector<bool>> visitados(n, vector<bool>(m, false));
      queue<pair<int,int>> cola;
      cola.push({my_soldier.pos.i, my_soldier.pos.j});
      visitados[my_soldier.pos.i][my_soldier.pos.j] = true;
      while (not cola.empty()) {
          
          auto i = cola.front().first;
          auto j = cola.front().second;
          cola.pop();
          for (int k = 0; k < 4; ++k) {
              
              int ii = i + di[k];
              int jj = j + dj[k];
              Cell casilla = cell(ii, jj);
              if (ii >= 0 and ii < n and jj >= 0 and jj < m and visitados[ii][jj] == false and casilla.type == Soil) {
                  
                  if (casilla.id != -1) {
                      
                      Ant su_hormiga = ant (casilla.id);
                      if (su_hormiga.player != me() and su_hormiga.type == Worker){
                          
                          Pos posicion(ii,jj);
                          return posicion;
                    }
                }
                  cola.push({ii,jj});
                  visitados[ii][jj] = true;
            }
        }
    }
    Pos vacio(-1,-1);
    return vacio;
  }
  
  void bfs_soldados (int id_soldier, vector<vector<int>>& huecos_ocupados) {
      
      Ant my_soldier = ant(id_soldier);
      //SOLDIER CON 1 DE VIDA
      if (my_soldier.life == 1) {
          
          if(todo_por_la_patria(my_soldier, huecos_ocupados)) return;
      }
      //MATAR, MATAR Y MATAR
      if(matar_matar_y_matar(my_soldier, huecos_ocupados)) return;
      //BUSCO HORMIGA PARA MATAR
      Pos pos_asesinato = buscar_hormiga(my_soldier);
      Pos vacio(-1,-1);
      if (pos_asesinato != vacio) {
          
          if(move_a_favor(my_soldier, pos_asesinato, huecos_ocupados)) return;
      }
      //MOVIMIENTO ALEATORIO
      if (move_random(my_soldier, huecos_ocupados)) return;
  }
  
  /**
   * Play method, invoked once per each round.
   */
  virtual void play () {
      
      vector<vector<int>> huecos_ocupados(board_rows());
      vector<int> reina = queens(me());
      bfs_reina(reina[0], huecos_ocupados);
      vector<int> soldados = soldiers(me());
      for (int i = 0; i < (int)soldados.size(); i++) bfs_soldados(soldados[i], huecos_ocupados);
      vector<int> trabajadoras = workers(me());
      for (int i = 0; i < (int)trabajadoras.size(); i++) bfs_trabajadoras(trabajadoras[i], huecos_ocupados);
  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
