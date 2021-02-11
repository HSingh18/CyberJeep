import { IonContent, IonHeader, IonPage, IonTitle, IonToolbar, IonListHeader, IonLabel, IonButton } from '@ionic/react';
import ExploreContainer from '../components/ExploreContainer';
import './Tab5.css';

const Tab5: React.FC = () => {
  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonTitle> Receiver Destination Location </IonTitle> 
          <IonListHeader>
            <IonLabel><p>Please Select Destination Location</p></IonLabel>
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
        <IonButton size="large" href="./tab6" class="button-native">Checkout</IonButton> 
        
      </IonContent> 

    </IonPage>
  );
};

export default Tab5;
