int monnaie_rendue() {
  comp = 0;
  while (argent != 0) {
    piece = 0;
    i = 0;
    for (i; i <= 8 ; i++) {
      vale = types[i];
      delay(5);
      if (argent >= vale && vale > piece)
      {
        piece = vale;
      }
    }
    list[comp] = piece;
    Serial.println(list[comp]);
    Serial.println("liste");
    delay(5);
    if (argent ==0){
     return(list);
     break; 
    }
    comp = comp + 1;
    argent = argent - piece;
  }
/*  for (i=0;i<50;i++){
    Serial.println(list[i]);
    delay(50);
    Serial.println("teste");
    if (list[i]==0){
      break;
    }
  }*/
}












void deuxE() {
  angles.write(294);
  delay(500);
  pousse.write(180);
  delay(500);
  pousse.write(0);
  delay(500);
  angles.write(0);
  delay(500);
}

void unE() {
  angles.write(202);
  delay(500);
  pousse.write(180);
  delay(500);
  pousse.write(0);
  delay(500);
  angles.write(0);
  delay(500);
}

void cinquanteC() {
  angles.write(247);
  delay(500);
  pousse.write(180);
  delay(500);
  pousse.write(0);
  delay(500);
  angles.write(0);
  delay(500);
}

void vingtC() {
  angles.write(158);
  delay(500);
  pousse.write(180);
  delay(500);
  pousse.write(0);
  delay(500);
  angles.write(0);
  delay(500);
}

void dixC() {
  angles.write(75.5);
  delay(500);
  pousse.write(180);
  delay(500);
  pousse.write(0);
  delay(500);
  angles.write(0);
  delay(500);
}

void cinqC() {
  angles.write(116);
  delay(500);
  pousse.write(180);
  delay(500);
  pousse.write(0);
  delay(500);
  angles.write(0);
  delay(500);
}

void deuxC() {
  angles.write(36.5);
  delay(500);
  pousse.write(180);
  delay(500);
  pousse.write(0);
  delay(500);
  angles.write(0);
  delay(500);
}

void unC() {
  pousse.write(0);
  delay(500);
  pousse.write(0);
  delay(500);
}
