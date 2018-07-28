void clearport(int port){
  id_card = (port-1)/64;
  id_ic = ((port-1)%64)/16;
  id_pin = (((port-1)%64)%16)+1;
  switch (id_card){
    case 0: 
      switch(id_ic){
      case 0: chip1.digitalWrite(0);chip1.pinMode(0); 
               break;
      case 1:  chip2.digitalWrite(0);chip2.pinMode(0);
               break;
      case 2:  chip3.digitalWrite(0);chip3.pinMode(0);
               break;
      case 3:  chip4.digitalWrite(0);chip4.pinMode(0);
         break;

      default:
         break;
        }break;
    case 1:
      switch(id_ic){
      case 0:  chip5.digitalWrite(0);chip5.pinMode(0);
               break;
      case 1: chip6.digitalWrite(0);chip6.pinMode(0); 
               break;
      case 2: chip7.digitalWrite(0);chip7.pinMode(0); 
               break;
      case 3: chip8.digitalWrite(0);chip8.pinMode(0); 
         break;
      default:
         break;    
    }break;
    case 2:
      switch(id_ic){
      case 0:  chip9.digitalWrite(0);chip9.pinMode(0);
               break;
      case 1: chip10.digitalWrite(0);chip10.pinMode(0); 
               break;
      case 2: chip11.digitalWrite(0);chip11.pinMode(0); 
               break;
      case 3: chip12.digitalWrite(0);chip12.pinMode(0); 
               break;
      default:
         break;    
    }break;
    case 3:
      switch(id_ic){
      case 0:  chip13.digitalWrite(0);chip13.pinMode(0);
               break;
      case 1: chip14.digitalWrite(0);chip14.pinMode(0); 
               break;
      case 2: chip15.digitalWrite(0);chip15.pinMode(0); 
               break;
      case 3: chip16.digitalWrite(0);chip16.pinMode(0); 
               break;
        default:
         break;    
    } break;
    case 4:
      switch(id_ic){
      case 0:  chip17.digitalWrite(0);chip17.pinMode(0);
               break;
      case 1: chip18.digitalWrite(0);chip18.pinMode(0); 
               break;
      case 2: chip19.digitalWrite(0);chip19.pinMode(0); 
               break;
      case 3: chip20.digitalWrite(0);chip20.pinMode(0); 
               break;
        default:
         break;    
    } break;
    case 5:
      switch(id_ic){
      case 0:  chip21.digitalWrite(0);chip21.pinMode(0);
               break;
      case 1: chip22.digitalWrite(0);chip22.pinMode(0); 
               break;
      case 2: chip23.digitalWrite(0);chip23.pinMode(0); 
               break;
      case 3: chip24.digitalWrite(0);chip24.pinMode(0); 
               break;
        default:
         break;    
    }break;
    case 6:
      switch(id_ic){
      case 0:  chip25.digitalWrite(0);chip25.pinMode(0);
               break;
      case 1: chip26.digitalWrite(0);chip26.pinMode(0); 
               break;
      case 2: chip27.digitalWrite(0);chip27.pinMode(0); 
               break;
      case 3: chip28.digitalWrite(0);chip28.pinMode(0); 
               break;
        default:
         break;    
    }break;
    case 7:
      switch(id_ic){
      case 0:  chip29.digitalWrite(0);chip29.pinMode(0);
               break;
      case 1: chip30.digitalWrite(0);chip30.pinMode(0); 
               break;
      case 2: chip31.digitalWrite(0);chip31.pinMode(0); 
               break;
      case 3: chip32.digitalWrite(0);chip32.pinMode(0); 
               break;
        default:
         break;    
    }break;
    /*
    case 8:
      switch(id_ic){
      case 0:  chip33.digitalWrite(0);chip33.pinMode(0);
               break;
      case 1: chip34.digitalWrite(0);chip34.pinMode(0); 
               break;
      case 2: chip35.digitalWrite(0);chip35.pinMode(0); 
               break;
      case 3: chip36.digitalWrite(0);chip36.pinMode(0); 
               break;
        default:
         break;    
    }break;
    case 9:
      switch(id_ic){
      case 0:  chip37.digitalWrite(0);chip37.pinMode(0);
               break;
      case 1: chip38.digitalWrite(0);chip38.pinMode(0); 
               break;
      case 2: chip39.digitalWrite(0);chip39.pinMode(0); 
               break;
      case 3: chip40.digitalWrite(0);chip40.pinMode(0); 
               break;
        default:
         break;    
    }break;
    case 10:
      switch(id_ic){
      case 0:  chip41.digitalWrite(0);chip41.pinMode(0);
               break;
      case 1: chip42.digitalWrite(0);chip42.pinMode(0); 
               break;
      case 2: chip43.digitalWrite(0);chip43.pinMode(0); 
               break;
      case 3: chip44.digitalWrite(0);chip44.pinMode(0); 
               break;
        default:
         break;    
    }break;
    case 11:
      switch(id_ic){
      case 0:  chip45.digitalWrite(0);chip45.pinMode(0);
               break;
      case 1: chip46.digitalWrite(0);chip46.pinMode(0); 
               break;
      case 2: chip47.digitalWrite(0);chip47.pinMode(0); 
               break;
      case 3: chip48.digitalWrite(0);chip48.pinMode(0); 
               break;
        default:
         break;    
    }break;
    case 12:
      switch(id_ic){
      case 0:  chip49.digitalWrite(0);chip49.pinMode(0);
               break;
      case 1: chip50.digitalWrite(0);chip50.pinMode(0); 
               break;
      case 2: chip51.digitalWrite(0);chip51.pinMode(0); 
               break;
      case 3: chip52.digitalWrite(0);chip52.pinMode(0); 
               break;
        default:
         break;    
    } break;
    case 13:
      switch(id_ic){
      case 0:  chip53.digitalWrite(0);chip53.pinMode(0);
               break;
      case 1: chip54.digitalWrite(0);chip54.pinMode(0); 
               break;
      case 2: chip55.digitalWrite(0);chip55.pinMode(0); 
               break;
      case 3: chip56.digitalWrite(0);chip56.pinMode(0); 
               break;
        default:
         break;    
    }break;
    case 14:
      switch(id_ic){
       case 0:  chip57.digitalWrite(0);chip57.pinMode(0);
               break;
      case 1: chip58.digitalWrite(0);chip58.pinMode(0); 
               break;
      case 2: chip59.digitalWrite(0);chip59.pinMode(0); 
               break;
      case 3: chip60.digitalWrite(0);chip60.pinMode(0); 
               break;
        default:
         break;    
    }break;
    case 15:
      switch(id_ic){
      case 0:  chip61.digitalWrite(0);chip61.pinMode(0);
               break;
      case 1: chip62.digitalWrite(0);chip62.pinMode(0); 
               break;
      case 2: chip63.digitalWrite(0);chip63.pinMode(0); 
               break;
      case 3: chip64.digitalWrite(0);chip64.pinMode(0); 
               break;
      default:
               break;   
    }   */
default:
         break;     
  }
}  