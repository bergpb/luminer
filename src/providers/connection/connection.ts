import 'rxjs/add/operator/map';
import { Http } from '@angular/http';
import { Storage } from '@ionic/storage';
import { Injectable } from '@angular/core';
import { LoadingController, AlertController, ToastController } from 'ionic-angular';

@Injectable()
export class ConnectionProvider {

  loading: any;

  constructor(public http: Http, 
              public loadingCtrl: LoadingController,
              public alertCtrl: AlertController, 
              public toastCtrl: ToastController,
              public storage: Storage) {}

  getRequest(url: string) {
    return this.http.get(url).map(
      res => res.json()
    );
  }

  saveUrl(data: string) {
    this.storage.set('urlApi', data);
  }

  removeUrl() {
    this.storage.remove('urlApi');
  }
  
  mostrarAviso(mensagem: string): any {
    let alert = this.alertCtrl.create({
      title: "Aviso!",
      subTitle: mensagem,
      buttons: ['OK']
    });
    return alert.present();
  }

  mostrarToast(mensagem: string): any {
    let toast = this.toastCtrl.create({
      message: mensagem,
      duration: 2000,
      position: 'top'
    });
    toast.present();
  }

  showLoading() {
    this.loading = this.loadingCtrl.create({
      content: 'Aguarde...',
      spinner: 'crescent'
    });
    return this.loading.present();
  }

  hideLoading(){
    return this.loading.dismiss();
  }

}
