unsigned long t;
bool m[30]  =   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
bool dc[30] =   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
bool df[30] =   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
bool mc[30] =   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
bool mf[30] =   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
bool deld[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
   
    bool rising(byte x)
    {   
    
        if (digitalRead(x) == 1 && dc[x] == 0) //0
                {
                  dc[x] = 1; 
                  //delay(20);
                  return 1;
                }
        else if (digitalRead(x) == 1 && dc[x] == 1) //
                {
                  //dc[x] = 0;
                  return 0;
                }
    
        else if (digitalRead(x) == 0  && dc[x] == 1) //
                {
                  dc[x] = 0;
                  return 0;
                }

        else if (digitalRead(x)== 0 && dc[x] == 0) 
                {
                   return 0; 
                }
    }

    bool falling(byte x)
    {    
        if (digitalRead(x) == 0 && df[x] == 0) //0
                {
                  df[x] = 1; 
                  //delay(20);
                  return 1;
                }
        else if (digitalRead(x) == 0 && df[x] == 1) //
                {
                  //dc[x] = 0;
                  return 0;
                }
    
        else if (digitalRead(x) == 1  && df[x] == 1) //
                {
                  df[x] = 0;
                  return 0;
                }
    }

void reset_t(unsigned long *tempo)
    {
      *tempo= millis();
    }

bool tiempos(int ti, int te, unsigned long tempo)
    {
        if (millis()-tempo >= ti && millis()-tempo <=te)
        {
           return 1;
        }
        else
        {
            return 0;
        }
        
    }

bool rising_m(bool x, byte dir)
{  
    if (x == 1 && mc[dir] == 0) 
            {
              mc[dir] = 1; 
              return 1;
            }
    else if (x == 1 && mc[dir] == 1) 
            { 
              return 0;
            }

    else if (x == 0  && mc[dir] == 1) 
            {
              mc[dir] = 0;
              return 0;
            }
    else if (x == 0 && mc[dir] == 0) 
    {
            return 0; 
    }
}

bool falling_m(bool y, byte dir)
{
    
    if (y == 0 && mf[dir] == 0) //0
            {
              mf[dir] = 1;   
              return 1;
            }
    else if (y == 0 && mf[dir] == 1) //
            {
              return 0;
            }

    else if (y == 1  && mf[dir] == 1) //
            {
              mf[dir] = 0;
              return 0;
            }
    else if (y == 1 && mc[dir] == 0) 
    {
            return 0; 
    }
}

bool t_on (bool in, int tiempo, unsigned long temporizador)
{
  if (millis()-temporizador >= tiempo && in == 1)
  {
      return 1;
  }
  else 
  {
      return 0;
  }
}

bool t_off (bool in, int tiempo, unsigned long temporizador)
{
  if (millis()-temporizador >= tiempo && in == 1)
  {
      return 0;
  }
  else 
  {
      return 1;
  }
}

void contador  (unsigned int *cont, unsigned int maximo)
{ 
    if (*cont < maximo)
    {
        //if(*act ==1)
        //{
        *cont+=1;
            //*act = 0;
        //}
    }
}

void reset_contador(unsigned int *cont)
{
    *cont=0;
}

float presion(float analog, float relacion, float vmax)
{
    float vout = analog*relacion;
    float psi  = (((vout/vmax)-0.1)/0.6667)*145.038;
    return psi;
    
  
  
} 

float calibracion(float pres, float v_real)
{
    float calibrado = v_real/pres;
    return calibrado;
}
