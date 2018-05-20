import 'rxjs/add/operator/map';
import { Http } from '@angular/http';
import { Storage } from '@ionic/storage';
import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import { ConnectionProvider } from '../../providers/connection/connection';

@Component({
  selector: 'page-home',
  templateUrl: 'home.html'
})
export class HomePage {
  cor: any;
  isLedOn: boolean;
  url: string;

  constructor(public navCtrl: NavController, 
              public connection: ConnectionProvider,
              public http: Http,
              public storage: Storage) {}

  ionViewWillEnter(){
    this.connection.showLoading();
    this.checarEstado();
  }

  checarEstado(){
    this.storage.get('urlApi').then(res => {
      if (res != null){
        this.url = res;
        let url = this.url+'/checar';
        this.connection.getRequest(url)
          .subscribe(
            res => {
              if(res.status.led_is === "on"){
                this.isLedOn = true;
              }
              else{
                this.isLedOn = false;
              }
            },
            err => {
              this.connection.mostrarToast(err);
            }
        );
        this.connection.hideLoading();
      }
      else{
        if(res == null){
          this.connection.mostrarToast("Url vazia, insira uma nova url.");
          this.connection.hideLoading();
        }
      }
    });
  }

  alteraEstado(){
    let url = this.url+'/alternar';
    this.connection.getRequest(url)
      .subscribe(
        res => {
          if(res.status.led_is == "on"){
            this.connection.mostrarToast("Ligado!");
            this.isLedOn = true;
          }
          else{
            this.connection.mostrarToast("Desligado!");
            this.isLedOn = false;
          }
        },
        err => {
          this.connection.mostrarAviso(err);
        }
    );
  }

  alteraCor(cor) {
    var urlCor = this.url+'/'+cor
    console.log(urlCor);
    this.connection.getRequest(urlCor)
      .subscribe(
        res => {
          let cor = res.status.color_is;
          this.connection.mostrarToast("Cor "+cor+" selecionada!");
          this.isLedOn = true;
        },
        err => {
          this.connection.mostrarAviso(err);
        }
      );
  }

}
