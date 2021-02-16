import { IonContent, IonCol, IonHeader, IonPage, IonTitle, IonToolbar, IonListHeader, IonLabel, IonButton, IonGrid, IonRow, IonItem } from '@ionic/react';
import ExploreContainer from '../components/ExploreContainer';
import './SenderCheckout.css';
import './Home.css';

const SenderCheckout: React.FC = () => {
  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonTitle> <p id="title">Sender Checkout</p> </IonTitle> 
          <IonListHeader>
            <IonLabel><p>Confirmation: Send Package To: [Destination]</p></IonLabel>
          </IonListHeader>
        </IonToolbar>
      </IonHeader>
      <IonContent fullscreen color="light">
        <IonGrid>
          <IonRow class="ion-padding-bottom">
          <img src="https://image.isu.pub/160107220226-1f891900ec09ac0e300a2a2014d8f490/jpg/page_1.jpg"></img> 
          </IonRow>
          <IonRow class="ion-justify-content-center">
            <IonButton size="large">Lock</IonButton>
          </IonRow>
          <IonRow class="ion-justify-content-center ion-padding-bottom">
            <IonButton size="large"  class="button-native">Unlock</IonButton>
          </IonRow>
          <IonRow class="ion-justify-content-center"> 
            <IonButton size="large"  class="button-native" href="./Home">Checkout</IonButton>
          </IonRow>
        </IonGrid>
      </IonContent> 

    </IonPage>
  );
};

export default SenderCheckout;
