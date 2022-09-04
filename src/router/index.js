import { createRouter, createWebHistory } from 'vue-router'

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path: '/',
      name: 'home',
      component: () => import('@/views/Home.vue')
    },
    {
      path: '/tags',
      name: 'tags',
      component: () => import('@/views/Tags.vue')
    },
    {
      path: '/categories',
      name: 'categories',
      component: () => import('@/views/Categories.vue')
    },
    {
      path: '/archives',
      name: 'archives',
      component: () => import('@/views/Archives.vue')
    },
    {
      path: '/about',
      name: 'about',
      component: () => import('@/views/About.vue')
    },
    {
      path: '/about/yume',
      name: 'yume',
      component: () => import('@/views/Personal.vue')
    },

    {
      path: '/friends',
      name: 'friends',
      component: () => import('@/views/Friends.vue')
    },
    {
      path: '/webstack',
      name: 'webstack',
      component: () => import('@/views/WebSites.vue')
    },
  ]
})

export default router
