import { IonContent, IonHeader, IonPage, IonTitle, IonToolbar, IonListHeader, IonLabel, IonButton, IonGrid, IonRow, IonItem } from '@ionic/react';
import ExploreContainer from '../components/ExploreContainer';
import './Tab6.css';

const Tab6: React.FC = () => {
  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonTitle> Receiver Destination Location </IonTitle> 
          <IonListHeader>
            <IonLabel><p>Confirmation: Send Package To: [Destination]</p></IonLabel>
          </IonListHeader>
        </IonToolbar>
      </IonHeader>
      <IonContent fullscreen>
        <IonHeader collapse="condense">
          <IonToolbar>
            <IonTitle size="large"></IonTitle>
          </IonToolbar>
        </IonHeader>
        
        <img src="https://image.isu.pub/160107220226-1f891900ec09ac0e300a2a2014d8f490/jpg/page_1.jpg"></img> 
          
        <IonButton size="large"  class="button-native">Lock</IonButton>
        <IonItem>
        
                <IonButton size="large"  class="button-native">Lock</IonButton>
               
                <IonButton size="large"  class="button-native">Unlock</IonButton>
               
                <IonButton size="large"  class="button-native">Checkout</IonButton>
               
        
        </IonItem>
      </IonContent> 

    </IonPage>
  );
};

export default Tab6;
