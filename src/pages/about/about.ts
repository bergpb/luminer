import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import { Storage } from '@ionic/storage';
import { ConnectionProvider } from '../../providers/connection/connection';


@Component({
  selector: 'page-about',
  templateUrl: 'about.html',
})
export class AboutPage {

  url: string;
  private_url: string;

  constructor(public navCtrl: NavController,
              public storage: Storage,
              public connection: ConnectionProvider) {}

  ionViewWillEnter() {
    this.storage.get('urlApi').then(res => {
      if (res != null){
        this.private_url = res;
      }
      else{
        this.private_url = 'vazio';
      }
    });
  }

  submitUrl() {
    this.connection.saveUrl('http://'+this.url);
    this.storage.get('urlApi').then(res => {
      this.connection.mostrarAviso('Endereço '+this.url+ ' salvo.');
      this.private_url = res;
    });
  }

  deleteUrl() {
    this.storage.remove('urlApi')
      .then(()=>{
        this.connection.mostrarAviso('Endereço apagado. Insira um novo para continuar.');
        this.private_url = '';
      });
  }

}
