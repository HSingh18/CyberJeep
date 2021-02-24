import React, { useState } from 'react';
import { IonContent, IonItem, IonLabel, IonSelect, IonSelectOption, IonButton,IonHeader, IonPage, IonTitle, IonToolbar, IonAlert } from '@ionic/react';
import ExploreContainer from '../components/ExploreContainer'; 
import './RequesterCheckout.css';
import { dis, gohome, } from '../toast';
/*import './RequestPACK.css'; */ 

const RequesterCheckout: React.FC = () => { 
  const [showAlert1, setShowAlert1] = useState(false);  
  
  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonTitle> Request Checkout </IonTitle>
        </IonToolbar>
      </IonHeader>
      <IonContent fullscreen >
        <IonHeader collapse="condense">
          <IonToolbar>
            <IonTitle size="large">Request Checkout</IonTitle>
          </IonToolbar>
        </IonHeader> 

        <IonButton  size="small"  class="button-native" onClick={() => setShowAlert1(true)} expand="block" >Checkout</IonButton>   

        

        <IonAlert
          isOpen={showAlert1}
          onDidDismiss={() => setShowAlert1(false)}
          cssClass='my-custom-class'
          header={'Alert'}
          subHeader={'Leaving Checkout!'}
          message={'You will be directed to home page'}
          buttons={[  
            {
              text:'Redirect to Home Page', 
            role: 'Redirect to Home Page', 
            cssClass: 'secondary', 
            handler: blah => {
              console.log('Confirm Cancel: blah'); 
              gohome(); 
          }}, 
          
          {
            text: 'Cancel',
            handler: () => {
            console.log('Confirm Okay'); 
            }
          } 
  
           ]} 
             
          /> 

          
           




      </IonContent>
    </IonPage> 
     
  ); 
};

export default RequesterCheckout;
