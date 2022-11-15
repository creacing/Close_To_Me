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
      path: '/tag',
      name: 'tag',
      component: () => import('@/views/Tag.vue')
    },
    {
      path: '/category',
      name: 'category',
      component: () => import('@/views/Category.vue')
    },
    {
      path: '/archive',
      name: 'archive',
      component: () => import('@/views/Archive.vue')
    },
    {
      path: '/about',
      name: 'about',
      component: () => import('@/views/About.vue')
    },
    {
      path: '/site',
      name: 'site',
      component: () => import('@/views/Site.vue')
    },
    {
      path: '/article/:type/:path',
      name: 'article',
      component: () => import('@/views/Post.vue')
    },
  ]
})

export default router
