import { IonContent, IonGrid, IonRow, IonCol, IonListHeader, IonLabel, IonHeader, IonImg, IonList, IonPage, IonTitle, IonToolbar, IonItem, IonButton } from '@ionic/react';
import ExploreContainer from '../components/ExploreContainer';
import './Tab1.css';

const Tab1: React.FC = () => {
  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonTitle><p id="title">Home</p></IonTitle>
        </IonToolbar>
      </IonHeader>
      <IonContent fullscreen color="light">
        <div id="title">
          <h2>Notifications</h2>
          <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/f8/Aspect-ratio-16x9.svg/1280px-Aspect-ratio-16x9.svg.png"></img>
        </div>
        <IonList>
          <IonListHeader>
            <IonLabel><h1>Notifications</h1></IonLabel>
          </IonListHeader>
          <IonItem>
            <IonGrid>
              <IonRow>
                <IonCol>
                  <p>Notification 1</p>
                </IonCol>
                <IonCol size="auto">
                  <IonButton size="small" href="./tab4" class="button-native">Button1</IonButton>
                </IonCol>
              </IonRow>
            </IonGrid>
          </IonItem>
          <IonItem>
            <IonGrid>
              <IonRow>
                  <IonCol>
                    <p>Notification 2</p>
                  </IonCol>
                  <IonCol size="auto">
                    <IonButton size="small" href="./tab3" class="button-native">Button2</IonButton>
                  </IonCol>
                </IonRow> 
            </IonGrid>
          </IonItem>
        </IonList>
      </IonContent>
    </IonPage>
  );
};

export default Tab1;
