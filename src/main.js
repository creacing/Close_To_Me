import { createApp } from 'vue'
import App from './App.vue'
import router from './router'
import { getPosts } from "@/utils/getPost.js";
import '@/assets/app.css'
import { createPinia } from 'pinia'

getPosts()
const app = createApp(App)

app.use(router)
app.use(createPinia())

app.mount('#app')
