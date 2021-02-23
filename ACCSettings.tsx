import React, { useState } from 'react';
import { IonContent, IonHeader, IonPage, IonTitle, IonToolbar, IonInput, IonButton, IonGrid, IonRow, IonCol } from '@ionic/react';
import { useEffect } from 'react'; 
import{Link} from 'react-router-dom';
import ExploreContainer from '../components/ExploreContainer';
import './ACCSettings.css'; 
import './Register.css'; 
import { gohome } from '../toast';

const ACCSettings: React.FC = () => {
  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonTitle> Account Settings </IonTitle>
        </IonToolbar>
      </IonHeader>
      <IonContent fullscreen class="ion-padding ion-text-center">
        <IonHeader collapse="condense">
          <IonToolbar>
            <IonTitle size="large"></IonTitle>
          </IonToolbar>
        </IonHeader>
   

        <IonInput  
            placeholder="Userame?"  
           
        ></IonInput>  
         <IonInput  
            placeholder="Email?"  
           
        ></IonInput>  
         
        <IonInput 
            type="password"
            placeholder="Password?" 
             
        ></IonInput>   
         <IonInput 
            type="password" 
            placeholder=" Confirm Password" 
            
        ></IonInput>  
        <IonGrid> 
        <IonRow> 
        <IonCol>
        <IonButton>Save</IonButton> 
        </IonCol>   
        <IonCol>
        <IonButton onClick={gohome}>Logout</IonButton> 
        </IonCol>
        </IonRow>
        </IonGrid>
      </IonContent>
    </IonPage>
  );
};

export default ACCSettings;
