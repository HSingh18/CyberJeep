import { IonContent, IonGrid, IonRow, IonCol, IonIcon ,IonListHeader, IonLabel, IonHeader, IonImg, IonList, IonPage, IonTitle, IonToolbar, IonItem, IonButton } from '@ionic/react';
import { arrowForward } from 'ionicons/icons';
import ExploreContainer from '../components/ExploreContainer';
import './Home.css';

const Home: React.FC = () => {
  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonTitle><p id="title">Home</p></IonTitle>
        </IonToolbar>
      </IonHeader>
      <IonContent fullscreen color="light">
        <div id="title">
          <h2>Name</h2>
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
                  <p>Manual Mode</p>
                </IonCol>
                <IonCol size="auto">
                  <IonButton size="small" href="./ManualMode" class="button-native">
                    Go To Manual Mode
                    <IonIcon slot="end" icon={arrowForward} />
                  </IonButton>
                </IonCol>
              </IonRow>
            </IonGrid>
          </IonItem>
          <IonItem>
            <IonGrid>
              <IonRow>
                  <IonCol>
                    <p>Settings</p>
                  </IonCol>
                  <IonCol size="auto">
                    <IonButton size="small" href="./tab4" class="button-native">
                      Go To Settings
                      <IonIcon slot="end" icon={arrowForward} />
                    </IonButton>
                  </IonCol>
                </IonRow>
            </IonGrid>
          </IonItem>
        </IonList>
      </IonContent>
    </IonPage>
  );
};

export default Home;
