import { createRouter, createWebHistory ,createWebHashHistory } from 'vue-router'

const router = createRouter({
  // history: createWebHistory(import.meta.env.BASE_URL),
  history: createWebHashHistory(),
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
      path: '/about/qy',
      name: 'qy',
      component: () => import('@/views/Personal.vue')
    },

    {
      path: '/friends',
      name: 'friends',
      component: () => import('@/views/Friends.vue')
    },
    {
      path: '/WebSites',
      name: 'WebSites',
      component: () => import('@/views/WebSites.vue')
    },
    {
      path: '/article/:type/:path',
      name: 'article',
      component: () => import('@/views/Post.vue')
    },
  ]
})

export default router
